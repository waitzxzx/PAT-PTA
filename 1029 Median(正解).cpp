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
	int cnt = (n+m+1)/2;//Ŀ����� 
	int res;
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		while(temp>a[index]&&index<n&&cnt){//���������������ڵ�ǰindexָ����� 
			index++;cnt--;//index�ƶ�,��������1 
		}
		if(cnt==0){//�����ʱ������������˵����λ���Ѿ����� 
			res=a[--index];//ע�����Ҫ����1��Ԫ�� 
			break;
		}
		cnt--;//û�е�����λ��λ��(��cnt����0)��������ټ���1��(��temp) 
		if(cnt==0){//�����ʱ����������ԭ��ͬ�� 
			res=temp;
			break;
		}
	}
	if(cnt){//������е�����������Ժ󣬻�û�г�����λ����˵����λ��������a[]�� 
		while(cnt--){
			index++;
		}
		res=a[--index];
		//res=a[index+cnt-1]; 
	}
	printf("%d\n",res);
	return 0;
}
