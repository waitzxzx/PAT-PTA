#include<stdio.h>
const int MAX = 1e5+7;
int cnt [MAX] = {0};
int st[MAX];
int size = 0;
int PeekMedian(){
	int mid = (size+1)/2;
	int num =0;
	for(int i=0;i<MAX;i++){
		if(cnt[i]>0){
			num+=cnt[i];
			if(num>=mid) return i;
		}
	}
}
int main(void){
	int n;
	scanf("%d",&n);
	char s[80];
	while(n--){
		scanf("%s",&s);
		if(s[1]=='o'){
			if(size>0){
				int top = st[size-1];
				printf("%d\n",top);
				cnt[top]--;
				size--;
			}
			else printf("Invalid\n"); 
		}
		else if(s[1]=='e'){
			if(size==0) printf("Invalid\n");  
			else printf("%d\n",PeekMedian());
		}
		else{
			int elem;
			scanf("%d",&elem);
			cnt[elem]++;
			size++;
			st[size-1] = elem;
		}
	}
	return 0;
}
