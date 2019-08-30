#include<iostream>
#include<vector>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 1017;
int N,M,K,DS;//houses stations roads 
int string2int(string s){
	//1 to N G1 to GM
	bool isStation =false;
	if(s[0]=='G'){
		s.erase(s.begin());
		isStation=true;
	}
	int ans = 0;
	for(int i=0;i<s.length();i++){
		ans = ans*10+s[i]-'0';
	}
	if(isStation) ans+=N;
	return ans;
}
struct Edge{
	int next;int weight;
	Edge(int n,int w):next(n),weight(w){ }
};
vector<Edge> graph[MAX];
bool visit[MAX];
int dis[MAX]; 
int main(void){
	cin>>N>>M>>K>>DS;
	string a,b;int dest;
	while(K--){
		cin>>a>>b>>dest;
		int p1 = string2int(a);
		int p2 = string2int(b); 
		graph[p1].push_back(Edge{p2,dest});
		graph[p2].push_back(Edge{p1,dest});
	}
	int bestStation = -1;int bestBound = 0;int bestTotal = INF;
	for(int k=N+1;k<=N+M;k++){//´Ók³ö·¢
		int newP = k;
		memset(dis,-1,sizeof(dis));
		memset(visit,false,sizeof(visit)); 
		dis[newP]=0;
		visit[newP]=true;
		int cnt=0;
		while(cnt<N)
		//for(int p=1;p<M+N;p++)
		{
			for(int i=0;i<graph[newP].size();i++){
				int cur = graph[newP][i].next;
				int w = graph[newP][i].weight;
				if(visit[cur]) continue;
				if(dis[cur]==-1||dis[newP]+w<dis[cur]){
					dis[cur]=w+dis[newP];
				}
			}
			int min = INF;
			for(int i=1;i<=N+M;i++){
				if(visit[i]) continue;
				if(dis[i]==-1) continue;
				if(dis[i]<min){
					min = dis[i];
					newP = i;
				}
			}
			visit[newP] = true;
			if(newP>=1&&newP<=N) cnt++;
		}
		int nearest = INF;int total=0;
		bool isOK = true;
		for(int i=1;i<=N;i++){
			if(dis[i]>DS){
				isOK = false;
				break;
			}
			nearest = min(nearest,dis[i]);
			total+=dis[i];
		}
		if(isOK){
			if(nearest>bestBound){
				bestStation = k;
				bestBound = nearest;
				bestTotal = total;
			}else if(nearest==bestBound&&total<bestTotal){
				bestStation = k;
				bestTotal = total;
			}
		}
	}
	if(bestStation==-1) cout<<"No Solution"<<endl;
	else{
		printf("G%d\n",bestStation-N);
		printf("%.1f %.1f\n",double(bestBound),double(bestTotal)/double(N));
	}
	return 0;
}
