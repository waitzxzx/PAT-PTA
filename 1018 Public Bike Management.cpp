#include<iostream>
#include<cstring>
#include<vector>
#define MIN 0x3f3f3f3f
using namespace std;
const int MAX = 507;
struct Edge{
	int next;int weight;
	Edge(int n,int w):next(n),weight(w){}
};
vector<Edge> graph[MAX];
bool visit[MAX]={false};
int dis[MAX];//距离 
int last[MAX];//上一个车站 
int need[MAX];//当前车站需要的车辆数 
int needSum[MAX]={0};//从起点到当前位置沿途需要多少车辆 
void dfs(int dest){
	if(dest==0){
		cout<<dest;
		return;
	}
	dfs(last[dest]);
	cout<<"->"<<dest;
}
int main(void){
	int C,N,D,M;
	cin>>C>>N>>D>>M;
	int si,sj,time,a;
	for(int i=1;i<=N;i++){
		cin>>a;
		need[i] = C/2-a;
	}
	for(int i=0;i<M;i++){
		cin>>si>>sj>>time;
		graph[si].push_back(Edge(sj,time));
		graph[sj].push_back(Edge(si,time));
	} 
	memset(dis,-1,sizeof(dis));
	int newP = 0;
	visit[newP]=true;dis[0]=0;
	while(!visit[D]){
		for(int i=0;i<graph[newP].size();i++){
			int v = graph[newP][i].next;
			int w = graph[newP][i].weight;
			if(visit[v]) continue;
			if(dis[v]==-1||dis[newP]+w<dis[v]){
				dis[v]=dis[newP]+w;
				needSum[v] = needSum[newP]+need[v];
				last[v] = newP;
			}else if(dis[newP]+w==dis[v]){
				if((needSum[newP]+need[v]<needSum[v]&&needSum[v]>0)||(needSum[newP]+need[v]>needSum[v]&&needSum[v]<=0&&needSum[newP]+need[v]<=0)){
					needSum[v] = needSum[newP]+need[v];
					last[v] = newP;
				}
			}
		}
		int min = MIN;
		for(int i=1;i<=N;i++){
			if(visit[i]) continue;
			if(dis[i]==-1) continue;
			if(dis[i]<min){
				min = dis[i];
				newP = i;
			}
		}
		visit[newP] = true;
	}
	if(needSum[D]>=0) cout<<needSum[D]<<" ";
	else cout<<"0 ";
	dfs(D);
	if(needSum[D]>=0) cout<<" 0"<<endl;
	else cout<<" "<<-needSum[D]<<endl;
	return 0;
}
