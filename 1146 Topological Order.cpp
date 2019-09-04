#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 1007;
int G[MAX][MAX]={0};
int graph[MAX][MAX];
int I[MAX]={0};
int inDegree[MAX];
int order[MAX];
int N,M,K;
bool topo(){
	for(int i=1;i<=N;i++){
		int cur = order[i];
		if(inDegree[cur]==0){
			for(int j=1;j<=N;j++){
				if(graph[cur][j]==1){
					graph[cur][j]=0;
					inDegree[j]--;
				}
			}
		}
		else return false;
	}
	return true;
}
int main(void){
	cin>>N>>M;
	int a,b;
	while(M--){
		cin>>a>>b;
		G[a][b]=1;
		I[b]++;
	}
	cin>>K;bool first = true;
	for(int i=0;i<K;i++){
		for(int i=1;i<=N;i++) cin>>order[i];
		memcpy(graph,G,sizeof(G));
		memcpy(inDegree,I,sizeof(I));
		if(!topo()){
			if(first) cout<<i,first=false;
			else cout<<" "<<i;
		}
	}
}
