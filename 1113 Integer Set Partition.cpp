#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll a[100007];
int main(void){
	int N;scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%lld",&a[i]);
	sort(a,a+N);
	ll sum = 0;
	for(int i=0;i<N;i++){
		if(i<N/2) sum=sum-a[i];
		else sum+=a[i];
	}
	if(N%2==0) printf("0 ");
	else printf("1 ");
	printf("%lld\n",sum);
	return 0;
}
