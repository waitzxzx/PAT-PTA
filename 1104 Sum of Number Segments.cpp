#include<iostream>
using namespace std;
const int MAX = 1e5+13;
double a[MAX]={0};
double sum[MAX]={0};
int main(void){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	double ans=0.0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans=ans+(sum[j]-sum[i-1]);
		}
	}
	printf("%.2f\n",ans);
	return 0;
}
