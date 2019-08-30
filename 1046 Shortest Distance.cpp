#include<iostream>
using namespace std;
const int N = 1e5+7; 
int num[N];
int shortdis(int p1,int p2,int n){
	if(p1==p2) return 0;
	if(p1>p2){
		int tmp = p1;
		p1 = p2;
		p2 = tmp;
	}
	int a1=0,a2=0;
	for(int i=p1;i<p2;i++) a1+=num[i];
	for(int i=p2;i<=n;i++) a2+=num[i];
	for(int i=1;i<p1;i++) a2+=num[i];
	return a1>a2?a2:a1;
}
int main(void){
	int n,m,p1,p2;cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i];
	cin>>m;
	while(m--){
		cin>>p1>>p2;
		int ans = shortdis(p1,p2,n);
		cout<<ans<<endl;
	}
	return 0;
}
