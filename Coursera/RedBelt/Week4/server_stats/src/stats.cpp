#include "http_request.h"
#include <string_view>
#include <map>
#include "stats.h"
//#include <iostream>

using namespace std;


	Stats::Stats(){
		method_stat_["GET"] =0;
		method_stat_["POST"] =0;
		method_stat_["DELETE"] =0;
		method_stat_["PUT"] =0;
		method_stat_["UNKNOWN"] =0;
		uri_stat_["/"] = 0;
		uri_stat_["/order"] = 0;
		uri_stat_["/product"] = 0;
		uri_stat_["/basket"] = 0;
		uri_stat_["/help"] = 0;
		uri_stat_["unknown"] = 0;
	}


  void Stats::AddMethod(string_view method){
	  if(method == "GET" || method == "POST"
	  				|| method == "DELETE" || method == "PUT") {
		  ++method_stat_[method];
	  } else {
		  ++method_stat_["UNKNOWN"];
	  }

  }


  void Stats::AddUri(string_view uri){
	  if( uri == "/" || uri == "/order" || uri == "/product"
	  					|| uri == "/basket" || uri == "/help") {
		  	  	  ++uri_stat_[uri];
	  } else {
		  ++uri_stat_["unknown"];
	  }

  }


  const map<string_view, int>& Stats::GetMethodStats() const {
	  return method_stat_;
  }


  const map<string_view, int>& Stats:: GetUriStats() const{
	  return uri_stat_;
  }


HttpRequest ParseRequest(string_view line){

		size_t pos0 =0;
		size_t pos = line.find_first_of(' ', pos0);
		while(pos-pos0==0){
			++pos0;
			pos = line.find_first_of(' ', pos0);
		}
		string_view method  = line.substr(pos0, pos-pos0);
//		cout << "method =" << method << endl;

		pos0 = pos;
		++pos0;
		pos = line.find_first_of(' ', pos0);


		string_view uri = line.substr(pos0, pos-pos0);
//		cout << "uri= " <<  uri << endl;
//		if( uri == "/" || uri == "/order" || uri == "/product"
//					|| uri == "/basket" || uri == "/help") {
//							pos0 = pos;
//							++pos0;
//							pos = line.find_first_of('/', pos0);
//							cout << "http = " << line.substr(pos0, pos-pos0) << endl;
//							if(line.substr(pos0,pos-pos0)== "HTTP") {

								++pos;
//								cout <<  "M=" <<method
//										<<"U="<< uri
//										<<"V=" << line.substr(pos, line.size()-pos) << endl;
								return {method, uri,  line.substr(pos, line.size()-pos)};
//							}

//			}
//				return {method, "unknown", ""};



}
