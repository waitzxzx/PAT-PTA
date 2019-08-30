//Çø·Ö%d %3d %03d %.3d 
#include<iostream>
#include<cstring>
using namespace std;
int main(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	int sum = a + b;
	if(sum<0){
		printf("-");
		sum = -sum;
	}
	if(sum>=1000000){
		int x=sum/1000000;
		printf("%d,",x);
		int y=sum-x*1000000;
		printf("%03d,",y/1000);
		printf("%03d",y%1000);
	}
	else if(sum<1000000&&sum>=1000){
		printf("%d,%03d",sum/1000,sum%1000);
	} 
	else{
		printf("%d",sum);
	}
	return 0;
 } 
