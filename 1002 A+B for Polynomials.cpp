//注意double和float区别 
#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 2010;
double coe[MAX];
int main(void)
{
	memset(coe,0,sizeof(coe));
	int a_i,b_i,exp;
	float c;
	scanf("%d",&a_i);
	for(int i=0;i<a_i;i++){
		scanf("%d%f",&exp,&c);
		coe[exp]+=c;
		//printf("%f\n",coe[exp]);
	}
	scanf("%d",&b_i);
	for(int i=0;i<b_i;i++){
		scanf("%d%f",&exp,&c);
		coe[exp]+=c;
	}
	int k=0;
	for(int i=MAX;i>=0;i--){
		if(coe[i]!=0) k++; 
	}
	printf("%d",k);
	for(int i=MAX;i>=0;i--){
		if(coe[i]!=0){
			printf(" %d %.1f",i,coe[i]);
		}
	}
	printf("\n");
	return 0;
}
