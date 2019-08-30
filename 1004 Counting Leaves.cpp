#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 107;
vector<int> graph[MAX];
int level[MAX]={0};
int cnt[MAX]={0};
int maxLevel = 0;
void dfs(int v){
	if(graph[v].size()==0){
		cnt[level[v]]++;
		return;
	}
	for(int i=0;i<graph[v].size();i++){
		int cur = graph[v][i];
		level[cur]=level[v]+1;
		maxLevel = max(maxLevel,level[cur]);
		dfs(cur);
	}
}
int main(void){
	int N,M;cin>>N>>M;
	int id,k,a;
	while(M--){
		cin>>id>>k;
		while(k--){
			cin>>a;
			graph[id].push_back(a);
		}
	}
	int root = 1;
	dfs(root);
	for(int i=0;i<=maxLevel;i++){
		if(i==0) cout<<cnt[i];
		else cout<<" "<<cnt[i];
	}
	return 0;
} 
