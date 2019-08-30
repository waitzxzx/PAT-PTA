#include<iostream>
#include<map>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 400007; 
map<string,int> mp;
string names[MAX];
vector<int> courses[MAX];
int main(void){
	int N,K,idx,num;
	int cnt = 0;
	string s;
	cin>>N>>K;//学生数、课程数 
	while(K--){
		cin>>idx>>num;
		for(int i=0;i<num;i++){
			cin>>s;int cur;
			if(mp.find(s)!=mp.end()){
				cur = mp[s];
			}
			else{
				mp.insert({s,cnt});
				names[cnt]=s;
				cur = cnt;
				cnt++;
			}
			courses[cur].push_back(idx);
		}
	}
	while(N){
		cin>>s;
		if(mp.find(s)!=mp.end()){
			int stu = mp[s];
			sort(courses[stu].begin(),courses[stu].end());
			int size = courses[stu].size();
			cout<<names[stu]<<" "<<size;
			for(int i=0;i<size;i++){
				cout<<" "<<courses[stu][i];
			}
			cout<<endl;
		} 
		else{
			cout<<s<<" "<<"0"<<endl;
		}
		N--;
	}
	return 0;
} 
