#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int LEN = 107;
vector<int> graph[LEN];
int w[LEN];
int pre[LEN];
int N,M,S;
vector<int> leaves;
void dfs(int v,int curW){
	curW += w[v];
	if(curW>S||curW==S&&!graph[v].empty()) return; 
	if(graph[v].empty()&&curW==S){
		leaves.push_back(v);
	}
	for(int i=0;i<graph[v].size();i++){
		int cur = graph[v][i];
		dfs(cur,curW); 
	}
}
void backTracking(int n){
	if(pre[n]==-1){
		printf("%d",w[n]);
		return;
	}
	backTracking(pre[n]);
	printf(" %d",w[n]);
}
bool cmp(int a,int b){
	return w[a]>w[b];
}
int main(void){
	cin>>N>>M>>S;//all nodes/non-leaf/given
	for(int i=0;i<N;i++) cin>>w[i];
	int id,k,a;
	while(M--){
		cin>>id>>k;
		while(k--){
			cin>>a;
			graph[id].push_back(a);
			pre[a]=id; 
		}
		sort(graph[id].begin(),graph[id].end(),cmp);//重点，根据儿子节点的权值排序 
	}
	pre[0]=-1;
	dfs(0,0);
	for(int i=0;i<leaves.size();i++){
		backTracking(leaves[i]);
		cout<<endl;
	}
	return 0;
} 
