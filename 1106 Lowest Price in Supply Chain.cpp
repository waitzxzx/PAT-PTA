#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<cmath>
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 1e5+7;
vector<int> graph[MAX];
int level[MAX];
bool isRetailer[MAX]={false};
int minLevel = INF;
void bfs(int root){//BFS求出每一个结点的层次，并求出叶子节点的最低层次 
	queue<int> q;
	q.push(root);
	level[root]=0;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		if(isRetailer[top]){//如果这是一个叶子节点 
			minLevel=min(minLevel,level[top]);
		}
		for(int i=0;i<graph[top].size();i++){//否则遍历这些节点，更新它们的层次，并加入队列 
			int cur = graph[top][i];
			level[cur]=level[top]+1;
			q.push(cur);
		}
	}
}
int main(void){
	int N,K,a;double p,r;
	cin>>N>>p>>r;
	for(int i=0;i<N;i++){
		cin>>K;
		if(K==0) isRetailer[i]=true;
		while(K--){
			cin>>a;
			graph[i].push_back(a);
		}
	}
	int root = 0;
	bfs(root);
	int cnt =0;
	for(int i=0;i<N;i++){
		if(isRetailer[i]&&level[i]==minLevel) cnt++;
	}
	printf("%.4f %d",p*pow((1+0.01*r),minLevel),cnt);
}
