#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 1e4+7;
int Tree[MAX];
int a[MAX];
int findRoot(int x){
	if(Tree[x]==-1) return x;
	int temp = findRoot(Tree[x]);
	Tree[x]=temp;
	return temp;
}
int maxBird = 0;
int main(void){
	int N,k;cin>>N;
	memset(Tree,-1,sizeof(Tree));
	while(N--){
		cin>>k;
		for(int i=0;i<k;i++){
			cin>>a[i];
			maxBird = max(maxBird,a[i]);
		}
		for(int i=1;i<k;i++){
			int na = findRoot(a[i-1]);
			int nb = findRoot(a[i]);
			if(na!=nb) Tree[na]=nb;
		}
	}
	int cnt=0;
	for(int i=1;i<=maxBird;i++){
		if(Tree[i]==-1) cnt++;
	}
	cout<<cnt<<" "<<maxBird<<endl;
	int Q,x,y;cin>>Q;
	while(Q--){
		cin>>x>>y;
		x = findRoot(x);
		y = findRoot(y);
		if(x!=y) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
} 
