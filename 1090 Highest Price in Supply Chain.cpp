#include<iostream>
using namespace std;
const int N = 1e5+7;
int Tree[N];
int cnt,depth = 0;
int findRoot(int x){
	cnt++;
	if(Tree[x]==-1) return x;
	else return findRoot(Tree[x]);
}
int main(void){
	int n;double p,rate;
	cin>>n>>p>>rate;
	for(int i=0;i<n;i++) cin>>Tree[i];
	int num = 0;
	for(int i=0;i<n;i++){
		cnt = 0;
		findRoot(i);
		if(cnt>depth){
			depth=cnt;
			num = 1;
		}
		else if(cnt==depth){
			num++;
		}
	}
	for(int i=0;i<depth-1;i++){
		p = p *(1.00+0.01*rate);
	}
	printf("%.2f %d\n",p,num);
	return 0;
}

