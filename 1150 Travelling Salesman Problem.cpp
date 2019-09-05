#include<iostream>
#include<vector>
#include<cstring>
#include<set>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 207;
int N,M,K;
bool visit[MAX]={false};
int graph[MAX][MAX];
int main(void){
	cin>>N>>M;int a,b,dist;
	memset(graph,-1,sizeof(graph));
	for(int i=0;i<M;i++){
		cin>>a>>b>>dist;
		graph[a][b]=dist;
		graph[b][a]=dist;
	}
	cin>>K;
	int l,m;vector<int> v;
	int min = INF;int index =-1;
	for(int j=1;j<=K;j++){
		cin>>l;
		v.clear();
		for(int i=0;i<l;i++){
			cin>>m;
			v.push_back(m);
		}
		memset(visit,false,sizeof(visit));
		bool edgeExist = true;int total = 0;
		for(int i=0;i+1<v.size();i++){
			if(graph[v[i]][v[i+1]]==-1) edgeExist = false;
			else{
				total+=graph[v[i]][v[i+1]];
				visit[v[i+1]]=true; 
			}
		}
		cout<<"Path "<<j<<": ";
		if(!edgeExist){
			cout<<"NA "<<"(Not a TS cycle)"<<endl;
			continue;
		}
		bool isTSC = true;
		for(int i=1;i<=N;i++){
			if(!visit[i]){
				isTSC = false;
				break;
			}
		}
		if(!isTSC){
			cout<<total<<" (Not a TS cycle)"<<endl;
		}
		else{
			cout<<total;
			if(v.size()==N+1) cout<<" (TS simple cycle)"<<endl;
			else if(v.size()>N+1) cout<<" (TS cycle)"<<endl;
			if(total<min){
				index=j;
				min = total;
			}
		}
	}
	cout<<"Shortest Dist("<<index<<") = "<<min<<endl; 
	return 0;
}

