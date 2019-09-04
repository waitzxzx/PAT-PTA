#include<iostream>
#include<cstring>
using namespace std;
int main(void){
	int N;string s;cin>>N;
	while(N--){
		cin>>s;
		while(s[0]=='0') s.erase(s.begin());
		int a = stoi(s.substr(0,s.length()/2));
		int b = stoi(s.substr(s.length()/2));
		int c = stoi(s);
		if(a==0||b==0||c%(a*b)!=0) puts("No");
		else puts("Yes");
	}
	return 0;
} 
