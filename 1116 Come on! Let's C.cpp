#include<stdio.h>
const int MAX = 1e4+7;
bool isChecked[MAX]={false};
int rank[MAX]={0};
bool isPrime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(void){
	int n,a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		rank[a]=i;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		printf("%04d: ",a);
		if(rank[a]==0) printf("Are you kidding?\n");
		else if(isChecked[a]) printf("Checked\n");
		else{
			if(rank[a]==1) printf("Mystery Award\n");
			else if(isPrime(rank[a])) printf("Minion\n");
			else printf("Chocolate\n");
		}
		isChecked[a]=true;
	}
	return 0;
} 
