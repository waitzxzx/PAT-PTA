#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 507; 
int N,M;int S,D;
struct edge{
	int next;int time;int w;
	edge(int n,int t,int weight):next(n),time(t),w(weight){}
};
vector<edge> graph[MAX];
bool visit[MAX]={false};
int dis[MAX];
int pastNum[MAX];
int totalTime[MAX];
int pre[MAX];
void dfs(int x,vector<int> &v){
	if(x==S){
		v.push_back(x);
		return;
	}
	dfs(pre[x],v);
	v.push_back(x);
}
void output(vector<int> v){
	for(int i=0;i<v.size();i++){
		if(i==0) cout<<v[i];
		else cout<<" -> "<<v[i];
	}
}
int cmd;//1 Distance 2 Time
void Dijkstra(){
	int newP = S;
	visit[newP]=true;
	dis[newP]=0;
	totalTime[newP]=0;
	pre[newP]=-1;
	while(!visit[D]){
		for(int i=0;i<graph[newP].size();i++){
			int cur = graph[newP][i].next;
			int t = graph[newP][i].time;
			int w = graph[newP][i].w;
			if(visit[cur]) continue;
			if(cmd==1){
				if(dis[cur]==-1||dis[newP]+w<dis[cur]){
					dis[cur]=dis[newP]+w;
					//pastNum[cur]=pastNum[newP]+1;
					totalTime[cur]=totalTime[newP]+t;
					pre[cur]=newP;
				}
				else if(dis[newP]+w==dis[cur]&&totalTime[newP]+t<totalTime[cur]){
					//pastNum[cur]=pastNum[newP]+1;
					totalTime[cur]=totalTime[newP]+t;
					pre[cur]=newP;
				}
			}
			else if(cmd==2){
				if(totalTime[cur]==-1||totalTime[newP]+t<totalTime[cur]){
					totalTime[cur]=totalTime[newP]+t;
					pastNum[cur]=pastNum[newP]+1;
					pre[cur]=newP;
				}
				else if(totalTime[newP]+t==totalTime[cur]&&pastNum[newP]+1<pastNum[cur]){
					pastNum[cur]=pastNum[newP]+1;
					pre[cur]=newP;
				}
			}
		}
		int min = INF;
		for(int j=1;j<=N;j++){
			if(cmd==1){
				if(dis[j]==-1) continue;
			}
			else if(cmd==2){
				if(totalTime[j]==-1) continue;
			}
			if(visit[j]) continue;
			if(cmd==1){
				if(dis[j]<min){
					min = dis[j];
					newP = j;
				}
			}
			else if(cmd==2){
				if(totalTime[j]<min){
					min = totalTime[j];
					newP=j;
				}
			}
		}
		visit[newP]=true;
	}
}
int main(void){
	cin>>N>>M;
	int v1,v2,oneway,length,time;
	for(int i=0;i<M;i++){
		cin>>v1>>v2>>oneway>>length>>time;
		graph[v1].push_back(edge(v2,time,length));
		if(oneway==0) graph[v2].push_back(edge(v1,time,length));
	}
	int bestDistance,bestTime;
	cin>>S>>D;
	vector<int> v11,v22;
	for(cmd = 1;cmd<=2;cmd++){
		memset(visit,false,sizeof(visit));
		memset(dis,-1,sizeof(dis));
		memset(pre,-1,sizeof(pre));
		memset(totalTime,-1,sizeof(totalTime)); 
		memset(pastNum,0,sizeof(pastNum));
		Dijkstra();
		if(cmd==1){
			bestDistance = dis[D];
			dfs(D,v11);
		} if(cmd==2){
			bestTime=totalTime[D];
			dfs(D,v22);
		}
	}
	if(v11==v22){
		printf("Distance = %d; Time = %d: ",bestDistance,bestTime);
		output(v11);cout<<endl;
	}
	else{
		printf("Distance = %d: ",bestDistance);output(v11);printf("\n"); 
		printf("Time = %d: ",bestTime);output(v22);printf("\n");
	}
	return 0;
}
