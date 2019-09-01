#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
const int MAX =  1e5+7;
vector<int> graph[MAX];
bool visit[MAX]={false};
double sets[MAX];
double area[MAX];
struct family{
	int id;int m;double avgSets,avgArea;
	family(int i,int n,double as,double aa):id(i),m(n),avgSets(as),avgArea(aa){}
	bool operator < (const family &other) const{
		if(avgArea!=other.avgArea) return avgArea>other.avgArea;
		return id<other.id;
	}
	void output() const{
		printf("%04d %d %.3f %.3f\n",id,m,avgSets,avgArea);
	}
};
int cnt;double sumSets,sumArea;
void dfs(int v){
	cnt++;
	sumSets+=sets[v];
	sumArea+=area[v];
	visit[v]=false;
	for(int i=0;i<graph[v].size();i++){
		int cur = graph[v][i];
		if(visit[cur]){
			dfs(cur);
		}
	}
}
set<family> F;
int main(void){
	int N;cin>>N;
	int id,father,mother,k,a;
	for(int i=0;i<N;i++){
		cin>>id>>father>>mother>>k;
		visit[id]=true;
		if(father!=-1){
			visit[father]=true;
			graph[id].push_back(father);
			graph[father].push_back(id);
		}
		if(mother!=-1){
			visit[mother]=true;
			graph[id].push_back(mother);
			graph[mother].push_back(id);
		}
		while(k--){
			cin>>a;
			visit[a]=true;
			graph[id].push_back(a);
			graph[a].push_back(id);
		}
		cin>>sets[id]>>area[id]; 
	}
	for(int i=0;i<10000;i++){
		if(visit[i]){
			cnt = 0;sumSets=sumArea=0.0;
			dfs(i);
			F.insert(family(i,cnt,sumSets/double(cnt),sumArea/double(cnt)));
		}
	}
	set<family>::iterator it;
	printf("%d\n",(int)F.size());
	for(it=F.begin();it!=F.end();it++){
		(*it).output();
	}
	return 0;
} 
