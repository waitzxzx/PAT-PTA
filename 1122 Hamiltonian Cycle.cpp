#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int MAX = 207;
int N,M,K;
bool visit[MAX];
bool graph[MAX][MAX]={false};
vector<int> seq;
int main(void){
	cin>>N>>M;int a,b;
	memset(graph,false,sizeof(graph));
	for(int i=0;i<M;i++){
		cin>>a>>b;
		graph[a][b]=true;
		graph[b][a]=true;
	}
	cin>>K;int c,x;
	while(K--){
		bool flag = true;
		cin>>c;
		seq.clear();
		for(int i=0;i<c;i++){
			cin>>x;
			seq.push_back(x);
		};
		if(c!=N+1||seq[0]!=seq[c-1]){
			flag = false;
		}
		else{
			for(int i=1;i<=N;i++) visit[i]=false;
			for(int i=0;i+1<c;i++){
				if(!graph[seq[i]][seq[i+1]]){
					flag =false;
					break;
				}
				
					visit[seq[i+1]]=true;
				
			}
			if(flag){
				for(int i=1;i<=N;i++){
					if(!visit[i]){
						flag = false;
						break;
					}
				}				
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
