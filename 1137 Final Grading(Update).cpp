#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<cmath>
using namespace std;
struct grade{
	string id;int online=-1,mid=-1,final=-1;int total=0;
	void calculator(){
		if(mid>final) total=(int)(0.5+mid*0.4+final*0.6);
		else total=final;
	}
};
bool cmp(grade a,grade b){
	if(a.total!=b.total) return a.total>b.total;
	else return a.id<b.id;
}
unordered_map<string,grade> mp; 
vector<grade> v;
int P,M,N;
int main(void){
	cin>>P>>M>>N;//ONLINE MID FINAL
	string s;int n;
	for(int i=0;i<P;i++){
		cin>>s>>n;
		if(n<=900) mp[s].online = n;
	}
	for(int i=0;i<M;i++){
		cin>>s>>n;
		if(n<=100) mp[s].mid = n;
	}
	for(int i=0;i<N;i++){
		cin>>s>>n;
		if(n<=100) mp[s].final = n;
	}
	for(auto it:mp){
		if((it.second).online>=200){
			(it.second).calculator();
			if((it.second).total>=60){
				(it.second).id = it.first;
				v.push_back(it.second);
			}
			
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		cout<<v[i].id<<" "<<v[i].online<<" "<<v[i].mid<<" "<<v[i].final<<" "<<v[i].total<<endl;
	} 
	return 0; 
}

