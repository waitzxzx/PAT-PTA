#include<iostream>
#include<cstring>
#include<ctype.h>
#include<map>
using namespace std;
int main(void){
	string s;
	getline(cin,s);
	string word = "";
	map<string,int> mp;
	for(int i=0;i<s.length();i++){
		if(isalnum(s[i])){
			word+=tolower(s[i]);
		}else{
			if(word.length()>0){
				mp[word]++;
				word = "";
			}
		}
	}
	if(word.length()>0) mp[word]++;
	int max = 0;string ans;
	map<string,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		if(it->second>max){
			max = it->second;
			ans = it->first;
		}
	}
	cout<<ans<<" "<<max<<endl;
	return 0;
}
 
