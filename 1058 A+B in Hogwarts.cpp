#include<stdio.h>
int main(void){
	int G1,G2,S1,S2,K1,K2;
	int G3,S3,K3;
	int carry=0;
	scanf("%d.%d.%d",&G1,&S1,&K1);
	scanf("%d.%d.%d",&G2,&S2,&K2);
	K3 = (K1+K2)%29;
	carry = (K1+K2)/29;
	S3 = (S1+S2+carry)%17;
	carry = (S1+S2+carry)/17;
	G3 = G1+G2+carry;
	printf("%d.%d.%d\n",G3,S3,K3);
	return 0;
} 
