#include<iostream>
using namespace std;
const int A_MAX = 1007;
const int R_MAX = 2007;
int main(void){
	int N,M,exp;
	double coe;
	double a[A_MAX]={0};
	double res[R_MAX]={0};
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%lf",&exp,&coe);
		a[exp]+=coe;
	}
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		scanf("%d%lf",&exp,&coe);
		for(int i=0;i<A_MAX;i++){
			if(a[i]!=0){
				res[i+exp]+=a[i]*coe;
			}
		}
	}
	int r=0;
	for(int i=0;i<R_MAX;i++){
		if(res[i]!=0) {
			r++;
		}
	}
	printf("%d",r);
	for(int i=R_MAX-1;i>=0;i--){
		if(res[i]!=0){
			printf(" %d %.1f",i,res[i]);
		}
	}
	printf("\n");
	return 0;
}
