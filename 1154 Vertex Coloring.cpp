#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
const int MAX = 1e4+7;
int N,M,q,a,b;
int coloring[MAX];
vector<pair<int,int> >v;
int main(void){
	cin>>N>>M;
	while(M--){
		cin>>a>>b;
		v.push_back(pair<int,int>(a,b));
	}
	cin>>q;
	set<int> s;
	while(q--){
		s.clear();
		for(int i=0;i<N;i++){
			 cin>>coloring[i];
			 s.insert(coloring[i]);
		}
		bool isOk = true;
		for(int i=0;i<v.size();i++){
			if(coloring[v[i].first]==coloring[v[i].second]){
				isOk =false;break;
			}
		}
		if(isOk) cout<<s.size()<<"-coloring"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
