#include<iostream>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
const int MAX = 205;
struct Edge{
	int next;
	int cost;
	Edge(int n,int c){
		next = n;
		cost=c;
	}
};
vector<Edge> graph[MAX];//ͼ 
int h[MAX],dis[MAX],sumH[MAX];//�Ҹ�ֵ������㵽�ó��еľ��롢����������е��Ҹ�ֵ 
int paths[MAX],lastCity[MAX], pastCities[MAX];//����ó��е�·����������ó��е�ǰ�����С� 
bool visit[MAX]={false};
map<string,int> mp;
string names[MAX];
void dfs(int city){//���ݷ��ҳ�·�� 
	if(city==0){
		cout<<names[city];return;
	}
	dfs(lastCity[city]);
	cout<<"->"<<names[city];
} 
int main(void){
	int N,K;cin>>N>>K;
	cin>>names[0];
	mp.insert({names[0],0});
	for(int i=1;i<N;i++){
		cin>>names[i]>>h[i];
		mp.insert({names[i],i});
	}
	string a,b;int c;
	for(int i=0;i<K;i++){
		cin>>a>>b>>c;
		int ax = mp[a],bx = mp[b];
		graph[ax].push_back(Edge(bx,c));
		graph[bx].push_back(Edge(ax,c));
	}
	int dest = mp["ROM"];
	memset(dis,-1,sizeof(dis));
	memset(sumH,0,sizeof(sumH));
	memset(paths,0,sizeof(paths));
	memset(pastCities,0,sizeof(pastCities)); 
	dis[0]=0;paths[0]=1;//��ʼ��
	visit[0]=true;
	int newP = 0;
	while(!visit[dest]){
		for(int i=0;i<graph[newP].size();i++){
			int t = graph[newP][i].next;
			int c = graph[newP][i].cost;
			if(visit[t]) continue;
			if(dis[t]==-1||dis[newP]+c<dis[t]){//���ɴ�����и��̵�·�� 
				dis[t] = dis[newP]+c;//���µ������
				sumH[t] = sumH[newP]+h[t];//���µ���ó��е��Ҹ�ֵ
				paths[t] = paths[newP];//���µ���ó��е�·���� 
				lastCity[t] = newP;//���µ���ó��е�ǰ������ 
				pastCities[t] = pastCities[newP]+1;//���¾����ĳ������� 
			}
			else if(dis[newP]+c == dis[t]){//����ͬ���ȵ�·��
				paths[t] += paths[newP];//���µ���ó��е�·����
				if(sumH[t]<sumH[newP]+h[t]||
				(sumH[t]==sumH[newP]+h[t]&&pastCities[t]>pastCities[newP]+1))
				{
					sumH[t] = sumH[newP]+h[t];//���µ���ó��е��Ҹ�ֵ
					lastCity[t] = newP;//���µ���ó��е�ǰ������  
					pastCities[t] = pastCities[newP]+1;//���¾����ĳ������� 
				}  
			}
		}
		int min = 123123123;
		for(int i=0;i<N;i++){//Ѱ���µĽ����뼯�� 
			if(visit[i]) continue;
			if(dis[i]==-1) continue;
			if(dis[i]<min){
				min = dis[i];
				newP = i;
			}
		}
		visit[newP] = true;
	} 
	cout<<paths[dest]<<" "<<dis[dest]<<" "<<sumH[dest]<<" "<<sumH[dest]/pastCities[dest]<<endl;
	dfs(dest);
	return 0;
}
