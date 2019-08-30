#include<stdio.h>
int main(void){
	int K;scanf("%d",&K);
	int cards[55];
	int machine[55];
	int temp [55];
	for(int i=1;i<=54;i++){
		cards[i] = i;
		scanf("%d",&machine[i]);
	}
	while(K--){
		for(int i = 1;i<=54;i++){
			temp[machine[i]] = cards[i];
		}
		for(int i = 1;i<=54;i++){
			cards[i] = temp [i];
		}
	}
	char L[5]={'S','H','C','D','J'};
	for(int i=1;i<=54;i++){
		if(i==1) printf("%c%d",L[(cards[i]-1)/13],cards[i]-13*(int)((cards[i]-1)/13));
		else printf(" %c%d",L[(cards[i]-1)/13],cards[i]-13*(int)((cards[i]-1)/13));
	}
	printf("\n");return 0;
}
