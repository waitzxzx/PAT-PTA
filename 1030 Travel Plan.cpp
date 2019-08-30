#include<iostream>
#include<vector>
#include<cstring>
#define MAX 0x3f3f3f3f
using namespace std;
int N,M,S,D;
const int LEN = 505;
struct Edge{
	int next;int weight;int cost;//下一个结点、距离、花销 
	Edge(int n,int w,int c):next(n),weight(w),cost(c){	}
};
vector<Edge>graph [LEN];
int dis[LEN];//记录距离 
int sumCost[LEN];//当前总花销 
int last[LEN];//记录上一个城市 
bool visit[LEN]={false};
void dfs(int x){
	if(x==S){
		cout<<x;return;
	} 
	dfs(last[x]);
	cout<<" "<<x;
}
int main(void){
	cin>>N>>M>>S>>D;
	int a,b,w,c;
	for(int i=0;i<M;i++){
		cin>>a>>b>>w>>c;
		graph[a].push_back(Edge(b,w,c));
		graph[b].push_back(Edge(a,w,c));
	}
	memset(dis,-1,sizeof(dis));
	
	int newP = S;
	visit[newP] = true;
	dis[newP] = 0;
	while(!visit[D]){
		for(int i=0;i<graph[newP].size();i++){
			int v = graph[newP][i].next;
			int w = graph[newP][i].weight;
			int c = graph[newP][i].cost;
			if(visit[v]) continue;
			if(dis[v]==-1||dis[newP]+w<dis[v]){//不可达或者有更近的路径 
				dis[v] = dis[newP]+w;//更新距离 
				sumCost[v] = sumCost[newP]+c;//更新消耗
				last[v] = newP;//更新前驱城市 
			}
			else if(dis[newP]+w==dis[v]&&sumCost[newP]+c<sumCost[v]){//距离相等但是有更小的消耗 
				sumCost[v] = sumCost[newP]+c;//更新消耗
				last[v] = newP;//更新前驱城市 				
			} 
		}
		int min = MAX;
		for(int i=0;i<N;i++){
			if(dis[i]==-1) continue;
			if(visit[i]) continue;
			if(dis[i]<min){
				min = dis[i];
				newP = i;
			}
		} 
		visit[newP] = true;
	}
	dfs(D);
	cout<<" "<<dis[D]<<" "<<sumCost[D]<<endl;
	return 0;
}

