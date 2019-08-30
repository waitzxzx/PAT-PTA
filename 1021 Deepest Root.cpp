#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
const int MAX = 1e4+7;
int Tree[MAX];
int findRoot(int x){//Ѱ�Ҹ���� 
	if(Tree[x]==-1) return x;
	else{
		int temp = findRoot(Tree[x]);
		Tree[x] = temp;
		return temp;
	}
}
bool visit[MAX];
int maxLevel[MAX];//��i�������Ϊ���ڵ�ʱ������������
int level[MAX];//��ǰ���ڵ���,��i�����Ĳ��(���) 
vector<int> graph[MAX];
void dfs(int v,int curRoot){//Ѱ����curRootΪ���ڵ�,��v��ʼ�ĸ������Ĳ�� 
	visit[v]=true;
	for(int i=0;i<graph[v].size();i++){//����ÿ���ڽӽ�� 
		int k = graph[v][i];//��ǰ�ڽӽ�� 
		if(!visit[k]){
			level[k]=level[v]+1;
			maxLevel[curRoot]=max(level[k],maxLevel[curRoot]);//������������ 
			dfs(k,curRoot); 
		}
	} 
}
int main(void){
	int n,a,b;cin>>n;
	memset(Tree,-1,sizeof(Tree));
	for(int i=1;i<=n-1;i++){
		cin>>a>>b;
		int na = findRoot(a);
		int nb = findRoot(b);
		if(na!=nb) Tree[na]=nb;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int bCnt=0;//������ͨ��֧�� 
	for(int i=1;i<=n;i++){
		if(Tree[i]==-1) bCnt++;
	}
	if(bCnt>=2) cout<<"Error: "<<bCnt<<" components"<<endl;
	else{
		for(int i=1;i<=n;i++){
			memset(level,0,sizeof(level));
			memset(visit,false,sizeof(visit));
			dfs(i,i);//�����������
		} 
		int deepest = 0;
		for(int i=1;i<=n;i++) deepest=max(deepest,maxLevel[i]);
		for(int i=1;i<=n;i++){
			if(maxLevel[i]==deepest) cout<<i<<endl;
		}
	}
	return 0;
}
