#include<iostream>
using namespace std;
const int MAX = 200007;
int a[MAX];
int main(void)
{
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	int temp;
	int index=0;
	int cnt = (n+m+1)/2;//目标计数 
	int res;
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		while(temp>a[index]&&index<n&&cnt){//如果新输入的数大于当前index指向的数 
			index++;cnt--;//index移动,计数减少1 
		}
		if(cnt==0){//如果此时计数结束，则说明中位数已经产生 
			res=a[--index];//注意必须要回溯1个元素 
			break;
		}
		cnt--;//没有到达中位数位置(即cnt不是0)，则计数再减少1个(即temp) 
		if(cnt==0){//如果此时计数结束，原理同上 
			res=temp;
			break;
		}
	}
	if(cnt){//如果所有的数输入完毕以后，还没有出现中位数，说明中位数在序列a[]中 
		while(cnt--){
			index++;
		}
		res=a[--index];
		//res=a[index+cnt-1]; 
	}
	printf("%d\n",res);
	return 0;
}
