#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int N,M,K;
const int MAX = 307;
map<int,int> mp;//ID to index;
int gender[MAX];//index to gender;male 1 fa -1
int id[MAX];//index to ID
int idx =0;
bool graph[MAX][MAX];
int main(void){
	cin>>N>>M;string a,b;
	memset(graph,false,sizeof(graph));
	mp.clear();
	for(int i=0;i<M;i++){
		int na,nb;
		int ga=1;int gb=1;
		cin>>a;
		if(a[0]=='-'){
			a.erase(a.begin());
			ga = -1;
		} 
		na = stoi(a);
		if(mp.find(na)==mp.end()){
			mp[na]=idx;
			id[idx]=na;
			gender[idx]=ga;
			idx++;
		}
		cin>>b;
		if(b[0]=='-'){
			b.erase(b.begin());
			gb = -1;
		}
		nb = stoi(b);
		if(mp.find(nb)==mp.end()){
			mp[nb]=idx;
			id[idx]=nb;
			gender[idx]=gb;
			idx++;
		}
		graph[mp[na]][mp[nb]]=true;
		graph[mp[nb]][mp[na]]=true;
	}
	cin>>K;int start,end; 
	vector<pair<int,int> > v;
	while(K--){
		cin>>start>>end;
		if(mp.find(abs(start))==mp.end()||mp.find(abs(end))==mp.end()){
			cout<<"0"<<endl;continue;
		} 
		int x = mp[abs(start)];int y=mp[abs(end)];
		v.clear();
		for(int i=0;i<idx;i++){
			for(int j=0;j<idx;j++){
				if(x!=i&&i!=j&&j!=y&&x!=j&&i!=y&&graph[x][i]&&graph[i][j]&&graph[j][y]){
					if(gender[x]*gender[i]==1&&gender[y]*gender[j]==1) v.push_back(pair<int,int>(id[i],id[j]));
				} 
			}
		}
		sort(v.begin(),v.end());
		cout<<v.size()<<endl;
		for(auto it:v) printf("%04d %04d\n",it.first,it.second);
	}	
	return 0;
}
