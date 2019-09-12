#pragma once
#ifndef PALYNDROM_H_
#define PALYNDROM_H_

bool IsPalindrom(const string& str) {
	if(str.size()==0){return true;}
	vector<char> a;

	for(auto& i: str){
		a.push_back(i);
	}
	if(a.size()==1 ){return true;}
	else{
		for(int i=1; i <= ((static_cast<int>(a.size())))/2; ++i){
			if(a[i-1]!=a[static_cast<int>(a.size())-i]){return false;}

		}
	}
	return true;
}



#endif /* PALYNDROM_H_ */
