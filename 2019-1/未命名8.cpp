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
int K,N,M;
const int MAX = 1e3+7; 
int graph[MAX][MAX]; 
bool suspect[MAX]={false};
int Tree[MAX];
int findRoot(int x){
	if(Tree[x]==x) return x;
	else{
		int temp = findRoot(Tree[x]);
		Tree[x]=temp;
		return temp;
	} 
}
bool cmp(vector<int> v1,vector<int> v2){
	return v1[0]<v2[0];
}
int main(void){
	cin>>K>>N>>M;int c,r,d;
	memset(graph,0,sizeof(graph));
	while(M--){
		cin>>c>>r>>d;
		graph[c][r]=graph[c][r]+d;
	}
	for(int i=1;i<=N;i++){
		int shortPhone=0,callBack=0;
		for(int j=1;j<=N;j++){
			if(graph[i][j]>0&&graph[i][j]<=5){
				shortPhone++;
				if(graph[j][i]>0){
					callBack++;
				}
			}
		}
		if(shortPhone>K&&callBack*5<=shortPhone) suspect[i]=true;
	}
	for(int i=1;i<=N;i++) Tree[i]=i;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(suspect[i]&&suspect[j]&&graph[i][j]&&graph[j][i]){
				int na = findRoot(i);
				int nb = findRoot(j);
				if(na!=nb){
					Tree[na]=nb;
				}	
			}
		}
	}
	map<int,vector<int> > mp;
	vector< vector<int> > u;
	for(int i=1;i<=N;i++){
		if(suspect[i]){
			int head = findRoot(i);
			mp[head].push_back(i);
		}
	}
	for(auto j:mp){
		sort(j.second.begin(),j.second.end());
		u.push_back(j.second);
	}
	sort(u.begin(),u.end(),cmp);
	for(int i=0;i<u.size();i++){
		for(int j=0;j<u[i].size();j++){
			if(j==0) cout<<u[i][j];
			else cout<<" "<<u[i][j];
		}
		cout<<endl;
	}
	if(u.empty()) cout<<"None"<<endl;
	return 0;
}
