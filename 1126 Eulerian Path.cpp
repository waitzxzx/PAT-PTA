#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 507;
int cnt[MAX]={0};
int Tree[MAX];
int N,M;
int findRoot(int x){
	if(Tree[x]==-1) return x;
	else{
		int temp = findRoot(Tree[x]);
		Tree[x] = temp;
		return temp;
	}
}
int main(void){
	cin>>N>>M;int a,b;
	memset(Tree,-1,sizeof(Tree));
	while(M--){
		cin>>a>>b;
		cnt[a]++;
		cnt[b]++;
		int na = findRoot(a);
		int nb = findRoot(b);
		if(na!=nb){
			Tree[na]=nb;
		}//并查集，检查是否只有一个连通分支 
	}
	int k=0;
	for(int i=1;i<=N;i++){
		if(Tree[i]==-1) k++;
	}//计算连通分支数 
	for(int i=1;i<=N;i++){
		if(i==1) cout<<cnt[i];
		else cout<<" "<<cnt[i]; 	
	}
	cout<<endl;
	if(k==1){//如果连通 
		int odd=0;
		for(int i=1;i<=N;i++){
			if(cnt[i]%2!=0)  odd++;
		}
		if(odd==0) cout<<"Eulerian";
		else if(odd==2) cout<<"Semi-Eulerian";
		else cout<<"Non-Eulerian";
	}
	else cout<<"Non-Eulerian";
	
	return 0;
}
