#include<iostream>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
set<int> s;
vector<pair<int,int> > v;
int main(void){
	int N,M,k,a,b;cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>a>>b;
		v.push_back(pair<int,int>(a,b));
	}
	while(M--){
		cin>>k;
		s.clear();
		while(k--){
			cin>>a;
			s.insert(a);
		}
		bool isOk = true;
		for(auto it:v){
			if(s.find(it.first)!=s.end()&&s.find(it.second)!=s.end()){
				isOk = false;break;
			}
		}
		if(isOk) puts("Yes");
		else puts("No");
	}
	return 0;
}
