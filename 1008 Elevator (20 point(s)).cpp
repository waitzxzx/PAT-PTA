#include<iostream>
using namespace std;
int main(void){
	int n;
	int arr[107]={0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	int res = 0;
	for(int i=1;i<=n;i++){
		res+=5;
		if(arr[i]>arr[i-1]) res=res+6*(arr[i]-arr[i-1]);
		else res=res+4*(arr[i-1]-arr[i]);
	}
	printf("%d\n",res);
	return 0;
} 
