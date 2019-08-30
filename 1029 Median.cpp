#include<iostream>
using namespace std;
const int MAX = 200007;
int a[MAX],b[MAX];
int main(void)
{
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=0;i<m;i++) scanf("%d",&b[i]);
	int count=0,i=0,j=0;
	int pre;
	while(count<(n+m+1)/2){
		if(i<n&&j<m){
			if(a[i]<b[j]){
				pre = a[i];
				i++;
			} 
			else{
				pre = b[j];
				j++;
			}
		}
		else if(i>=n){
			pre = b[j];
			j++;
		}
		else{
			pre = a[i];
			i++;
		}
		count++;
	}
	printf("%d\n",pre);
	return 0;
}
