#include "search_server.h"
#include "iterator_range.h"
#include "profile.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>
#include <vector>		// �������
//#include <numeric>   // add



vector<string> SplitIntoWords(const string& line) {
  istringstream words_input(line);
  return {istream_iterator<string>(words_input), istream_iterator<string>()};
}

SearchServer::SearchServer(istream& document_input) {
  UpdateDocumentBase(document_input);
}

void SearchServer::UpdateDocumentBase(istream& document_input) {
  InvertedIndex new_index;

  for (string current_document; getline(document_input, current_document); ) {
    new_index.Add(move(current_document));
  }

  index = move(new_index);
}

void SearchServer::AddQueriesStream(

  istream& query_input, ostream& search_results_output
) {// ����� ��������� ����� �� ��������� ������ � ��������� �� ����������.
	LOG_DURATION("queri");
//	vector<size_t> docid_count(50000);  //
	vector<pair<size_t, size_t>> res(index.GetSize() > 5 ? index.GetSize() : 5);


  for (string current_query; getline(query_input, current_query); ) {
 //   const auto words = SplitIntoWords(current_query);    // ������� ����� ������ ���� ������� ����� ������ � ����
// ����� ����� �������� ��� �������� ������� � ������ ����� ��������� �������.

	  // Q- ����
	  // N ����������
    //map<size_t, size_t> docid_count;       // ����� �������� �� ������� ����� �������� ��� ����� id, � �������� ��� ���.
   // for (const auto& word : words) {
	  res.resize(index.GetSize() >5 ? index.GetSize() : 5);
	  for(auto& i : res){
		  i.first = 0;
		  i.second =0;
	  }
      for (const auto& word : SplitIntoWords(current_query)) {  //Q
      for (const pair<size_t,size_t>& docid : index.Lookup(word)) {

//        	docid_count[docid]++;

        	res[docid.first].first = docid.first;
        	res[docid.first].second += docid.second;


    }
      }
//      vector<pair<size_t, size_t>> res;
//      res = docid_count;
//      sort(res.begin(), res.end(), [](size_t lhs, size_t rhs){return lhs > rhs;});

//    vector<pair<size_t, size_t>> search_results(
//      docid_count.begin(), docid_count.end()			// ��������� ������ (������� map) �������� � ������
//    );
      auto it = remove_if(res.begin(), res.end(), [](const auto& p){return p.second ==0;});
      res.resize(it - res.begin());
      partial_sort(													// ���������� map �� �������� ������ ����� �������� ����� ����.
      begin(res),
	  res.size() <5 ? (res.begin() + res.size()) : res.begin() + 5,
      end(res),
      [](pair<size_t, size_t> lhs, pair<size_t, size_t> rhs) {
        int64_t lhs_docid = lhs.first;
        auto lhs_hit_count = lhs.second;
        int64_t rhs_docid = rhs.first;
        auto rhs_hit_count = rhs.second;
        return make_pair(lhs_hit_count, -lhs_docid) > make_pair(rhs_hit_count, -rhs_docid);
      }
    );
   // pair<size_t, size_t> p= {0,0};

    //res.erase(remove(res.begin(), res.end(), p), res.end());
      if(res.size()>5) {
    	  res.resize(5);
      }

    search_results_output << current_query << ':';
    for (auto& [docid,hitcount] : Head(res,5)) {  // for (auto [docid, hitcount] : (Head(res, 5))) {  //search_results, 5))) {   // ������� move � ����� auto ������� &


    	search_results_output << " {"
        << "docid: " << docid << ", "
        << "hitcount: " << hitcount << '}';

    }
    search_results_output << '\n';                                // ������� endl �� '\n'

//    res.clear();

      }
}

void InvertedIndex::Add(const string& document) {
  docs.push_back(move(document));

  const size_t docid = docs.size() - 1;
  map<string, size_t> temp;
  for(const auto& word : SplitIntoWords(docs.back())){
	  temp[word]++;
  }
  for (const auto& i : temp) {
    index[i.first].push_back({docid , i.second});
  }
}

vector<pair<size_t, size_t>> InvertedIndex::Lookup(const string& word) const {
  if (auto it = index.find(word); it != index.end()) {
    return it->second;
  } else {
    return {};
  }
}
