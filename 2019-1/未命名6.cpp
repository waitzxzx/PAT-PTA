#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<map>
#include<queue>
#include<set> 
#include<cmath>
using namespace std;
set<string> s;
int N,M;
bool hasAlumni=false;
string curMin = "99999999";
string curMinID;
string getBirth(string s){
	return s.substr(6,8);
}
int main(void){
	cin>>N;string input;
	while(N--){
		cin>>input;
		s.insert(input);
	}
	int count =0;
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>input;
		if(s.find(input)!=s.end()){//found
			count++;
			if(!hasAlumni||(hasAlumni&&getBirth(input)<curMin)){
				hasAlumni = true;
				curMin =getBirth(input);
				curMinID = input;
			}
		}
		else{
			if(!hasAlumni&&getBirth(input)<curMin){
				curMin =getBirth(input);
				curMinID = input;
			}
		}
	}
	cout<<count<<endl<<curMinID<<endl; 
	return 0;
}
