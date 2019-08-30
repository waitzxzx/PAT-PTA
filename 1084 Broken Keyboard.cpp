#include<iostream>
#include<cstring>
#include<set>
#include<ctype.h>
using namespace std;
void upper(string &s){
	for(int i=0;i<s.length();i++){
		if(islower(s[i])) s[i]=toupper(s[i]);
	}
}
int main(void){
	string s1,s2;
	cin>>s1>>s2;
	set<char> s;
	upper(s1);upper(s2);
	int i,j;
	for(i=0,j=0;i<s1.length()&&j<s2.length();i++){
		if(s1[i]==s2[j]) j++;
		else{
			if(s.find(s1[i])==s.end()){
				cout<<s1[i];
				s.insert(s1[i]);
			}
		}
	}
	while(i<s1.length()){
		if(s.find(s1[i])==s.end()){
			cout<<s1[i];
			s.insert(s1[i]);
		}
		i++;
	}
	cout<<endl;return 0;
} 
