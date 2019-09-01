#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5+7;
vector<int> graph[N];
int level[N];
void dfs(int v){
	for(int i=0;i<graph[v].size();i++){
		int cur = graph[v][i];
		level[cur] = level[v]+1;
		dfs(cur);
	}
}
int main(void){
	int n;double p,rate;
	cin>>n>>p>>rate;
	int a,root;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a==-1) root = i;
		else{
			graph[a].push_back(i);
		} 
	} 
	level[root]=0;
	dfs(root);
	int depth=0,cnt = 0;
	for(int i=0;i<n;i++){
		if(level[i]>depth){
			depth = level[i];
			cnt = 1;
		}else if(level[i]==depth) cnt++;
	}
	for(int i=0;i<depth;i++){
		p = p *(1.00+0.01*rate);
	}
	printf("%.2f %d\n",p,cnt);
	return 0;
}
