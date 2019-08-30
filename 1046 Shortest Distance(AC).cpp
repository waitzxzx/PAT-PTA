#include<iostream>
using namespace std;
const int N = 1e5+7; 
int num[N]={0};int sum[N]={0};int n;
void init(){
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+num[i];//sum[i] ´Ó1µ½i+1µÄ¾àÀë 
}
int shortdis(int p1,int p2){
	if(p1==p2) return 0;
	if(p1>p2){
		int tmp = p1;p1 = p2;p2 = tmp;
	}
	int a1 = sum[p2-1]-sum[p1-1];
	int a2 = sum[n]-a1;
	return a1>a2?a2:a1;
}
int main(void){
	int m,p1,p2;cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i];
	init();
	cin>>m;
	while(m--){
		cin>>p1>>p2;
		int ans = shortdis(p1,p2);
		cout<<ans<<endl;
	}
	return 0;
}
