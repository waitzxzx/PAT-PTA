#include<iostream>
#include<vector> 
#define INF 1e9
using namespace std;
const int MAXN = 505;
struct Edge{
	int next;int w;
};
int N,M,from,to;
int emer[MAXN],dis[MAXN];	//救护队数量，距离 
int total[MAXN]={0},ways[MAXN]={0};	//到该位置总共的救护队数量，路径数量 
vector<Edge> G[MAXN];
bool mark[MAXN]={false}; 
int main(void){
	cin>>N>>M>>from>>to;	//N个城市，M条道路，出发城市，目标城市 
	fill(dis,dis+MAXN,INF);//和memset区分
	for(int i=0;i<N;i++) cin>>emer[i];	
	for(int i=0;i<M;i++){
		Edge E;
		int a,b,len;
		cin>>a>>b>>len;
		E.next=b; E.w=len;
		G[a].push_back(E);
		E.next=a;
		G[b].push_back(E);
	} 
	mark[from]=true;
	total[from]=emer[from];
	ways[from]=1;
	dis[from]=0;
	int newP=from;
	for(int k=1;k<N;k++){
		for(int j=0;j<G[newP].size();j++){
			int t = G[newP][j].next;
			int c = G[newP][j].w;
			//if(mark[t]==true) continue;
			if(dis[newP]+c<dis[t]){	//情况1，有更短的路径，更新距离、路径数、总救援队数量 
				dis[t]=dis[newP]+c;
				ways[t]=ways[newP];
				total[t]=total[newP]+emer[t];
			}
			else if(dis[newP]+c==dis[t]){	//情况2，有相同长度的路径，更新路径数、 
				ways[t]+=ways[newP]; 
				if(total[t]<total[newP]+emer[t])
					total[t]=total[newP]+emer[t];//当新路径上有更多的救援队的时候更新 
			}
		}
		
		int min = INF;
		for(int j=0;j<N;j++){
			if(mark[j]==true) continue;
			if(dis[j]==INF) continue;
			if(dis[j]<min){
				min = dis[j];
				newP = j;
			}
		}
		mark[newP]=true;
	}
	cout<<ways[to]<<" "<<total[to]<<endl;
	return 0;
} 
