#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<cmath>
using namespace std;
const int MAX = 3e4+7;
struct grade{
	string id;int online=-1,mid=-1,final=-1;int total=0;
	void calculator(){
		if(mid>final) total=(int)round(0.40*(double)mid+0.60*(double)final);
		else total=final;
	}
	bool operator < (const grade &other) const{
		if(total!=other.total) return total>other.total;
		return id<other.id;
	}
};
unordered_map<string,int> mp;//name-index 
grade G[MAX];
vector<grade> v;
int main(void){
	int P,M,N;cin>>P>>M>>N;//ONLINE MID FINAL
	int index = 0;string s;int n;
	mp.clear();
	for(int i=0;i<P;i++){
		cin>>s>>n;
		if(mp.find(s)!=mp.end()){
			G[mp[s]].online=n;
		}else{
			mp.insert({s,index});
			index++;
			G[mp[s]].online=n;
			G[mp[s]].id=s;
		}
	}
	for(int i=0;i<M;i++){
		cin>>s>>n;
		if(mp.find(s)!=mp.end()){
			G[mp[s]].mid=n;
		}else{
			mp.insert({s,index});
			index++;
			G[mp[s]].mid=n;
			G[mp[s]].id=s;
		}
	}
	for(int i=0;i<N;i++){
		cin>>s>>n;
		if(mp.find(s)!=mp.end()){
			G[mp[s]].final=n;
		}else{
			mp.insert({s,index});
			index++;
			G[mp[s]].final=n;
			G[mp[s]].id=s;
		}
	}
	for(int i=0;i<index;i++){
		G[i].calculator();
		if(G[i].online>=200&&G[i].total>=60){
			v.push_back(G[i]);
		}
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++) cout<<v[i].id<<" "<<v[i].online<<" "<<v[i].mid<<" "<<v[i].final<<" "<<v[i].total<<endl;
	return 0; 
}

