#include<iostream>
using namespace std;
int maxOfArray(double a[],int n){
	int index = 0;
	for(int i=0;i<n;i++){
		if(a[i]>a[index]) index=i;
	}
	return index;
} 
void printRes(int index){
	if(index==0) printf("W ");
	else if(index==1) printf("T ");
	else printf("L ");
}
int main(void){
	double res=1.0;
	double arr[3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%lf",&arr[j]);
		}
		int idx=maxOfArray(arr,3);
		printRes(idx);
		res=res*arr[idx];
	}
	printf("%.2f\n",(res*0.65-1)*2.0);
	return 0;
} 
