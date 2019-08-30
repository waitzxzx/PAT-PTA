#include<iostream>
#include<string>
using namespace std;
const int LEN = 128;
bool mark[LEN]={false};
int main(void){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0;i<s2.length();i++){
		mark[s2[i]]=true;
	}
	for(int i=0;i<s1.length();i++){
		if(!mark[s1[i]]) cout<<s1[i];
	}
	cout<<endl;
	return 0;
} 
