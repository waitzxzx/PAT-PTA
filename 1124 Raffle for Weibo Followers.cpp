#include<iostream>
#include<cstring>
#include<unordered_set>
#include<vector>
using namespace std;
int M,N,S;
const int MAX =1007;
string s[MAX];
unordered_set<string> ans;
int main(void){
	cin>>M>>N>>S;
	for(int i=1;i<=M;i++){
		cin>>s[i];
	}
	for(int i=S;i<=M;i=i+N){
		while(i<=M){
			if(ans.find(s[i])==ans.end()){
				cout<<s[i]<<endl;
				ans.insert(s[i]);
				break; 
			}
			i++;
		}
	}
	if(ans.empty()) cout<<"Keep going..."<<endl;
	return 0;
} 
