#include<iostream>
#include<vector>
#include<queue>
#define MAX 0x3f3f3f3f
using namespace std;
const int N = 1e3+7;
vector<int> followers[N];
int bfs(int k,int L){
	int cnt = 0;
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(k);
	bool mark[N]={false};
	int level[N];
	for(int i=0;i<N;i++) level[i]=MAX;
	mark[k]=true;
	level[k]=0;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i=0;i<followers[v].size();i++){
			int u = followers[v][i];
			if(mark[u]==false&&level[v]+1<=L){
				cnt++;
				mark[u]=true;
				level[u]=level[v]+1;
				q.push(u);
			}
		}
	}
	return cnt;
}
int main(void)
{
	int N,L;
	cin>>N>>L;
	int n,a,k;
	for(int i=1;i<=N;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a;
			followers[a].push_back(i);	
		}
	}
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>n;
		cout<<bfs(n,L)<<endl;
	}
	return 0;
}
