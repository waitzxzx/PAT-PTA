#include<stdio.h>
int main(void){
	int M,N,a;
	scanf("%d%d",&M,&N);
	int ans,cnt=0;
	for(int i=0;i<M*N;i++){
		scanf("%d",&a);
		if(a == ans) cnt++;
		else{
			if(cnt==0){
				ans = a;cnt++;
			}else{
				cnt--;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
} 
