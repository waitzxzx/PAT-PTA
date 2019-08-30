//bfs 
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define LL long long
using namespace std;
const int MAX = 1e5+7;
vector<int> graph[MAX];
int level[MAX]={0};
bool visit[MAX]={false};
int cnt[MAX]={0};
queue<int> q;
void bfs(int root){
	q.push(root);
	visit[root]=true;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		for(int i=0;i<graph[top].size();i++){
			int cur = graph[top][i];
			if(!visit[cur]){
				visit[cur]=true;
				level[cur]=level[top]+1;
				q.push(cur);
			}
		} 
	}
}
double price[MAX];
void init(double p,double r){
	price[0]=p;
	for(int i=1;i<MAX;i++){
		price[i]=price[i-1]*(1+0.01*r);
	}
}
int main(void){
	int n;double p,rate;
	cin>>n>>p>>rate;
	int a,b;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a==0){
			cin>>b;
			cnt[i]=b;
		}else{
			while(a--){
				cin>>b;
				graph[i].push_back(b);
				graph[b].push_back(a);
			}
		}
	}
	bfs(0);
	init(p,rate);
	double ans = 0;
	for(int i=0;i<n;i++){
		if(cnt[i]>0){
			ans += double(cnt[i])*price[level[i]];
		}
	}
	printf("%.1f\n",ans);
	return 0;
}
