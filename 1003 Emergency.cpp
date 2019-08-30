#include<iostream>
#include<vector> 
#define INF 1e9
using namespace std;
const int MAXN = 505;
struct Edge{
	int next;int w;
};
int N,M,from,to;
int emer[MAXN],dis[MAXN];	//�Ȼ������������� 
int total[MAXN]={0},ways[MAXN]={0};	//����λ���ܹ��ľȻ���������·������ 
vector<Edge> G[MAXN];
bool mark[MAXN]={false}; 
int main(void){
	cin>>N>>M>>from>>to;	//N�����У�M����·���������У�Ŀ����� 
	fill(dis,dis+MAXN,INF);//��memset����
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
			if(dis[newP]+c<dis[t]){	//���1���и��̵�·�������¾��롢·�������ܾ�Ԯ������ 
				dis[t]=dis[newP]+c;
				ways[t]=ways[newP];
				total[t]=total[newP]+emer[t];
			}
			else if(dis[newP]+c==dis[t]){	//���2������ͬ���ȵ�·��������·������ 
				ways[t]+=ways[newP]; 
				if(total[t]<total[newP]+emer[t])
					total[t]=total[newP]+emer[t];//����·�����и���ľ�Ԯ�ӵ�ʱ����� 
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
