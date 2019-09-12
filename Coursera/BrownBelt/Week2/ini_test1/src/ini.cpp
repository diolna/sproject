#include "ini.h"

#include <string>
#include <unordered_map>
#include <string_view>
#include <iostream>
#include <tuple>

using namespace std;

//namespace Ini {

pair<string_view, string_view> Split(string_view line, char by) {
	  size_t pos = line.find(by);
	  string_view left = line.substr(0, pos);
	  if (pos < line.size() && pos + 1 < line.size()) {
	     return {left, line.substr(pos + 1)};
	  } else {
		  return {left, string_view()};
  }
}

namespace Ini {
Section& Document::AddSection(string name) {
		//pair<string, Section> p= make_pair(name, make_pair("aaa","bbb"));
		//sections.insert(p);
		return sections[move(name)];
}

const Section& Document::GetSection(const string& name) const{
	return sections.at(name);

}

size_t Document::SectionCount() const {
	return sections.size();
}

Document Load(istream& input){
	Document doc;
	string name_section;
	string name;
	Section* s;
	while(getline(input, name_section)) {
		if(name_section[0] == '['){

			name = name_section.substr(1, name_section.size()-2);
			s = &doc.AddSection(name);

		}else {
			if(name_section!=""){
				pair<string_view, string_view> p =  Split(name_section, '=');
				s->insert(p);

			}
		}


	}

	return doc;

}

}
