#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX = 1e5+7; 
int a[MAX]={0};
bool comp(const int &a,const int &b)
{
    return a>b;
}
int main(void){
	int N;cin>>N;
	for(int i=0;i<N;i++) cin>>a[i];
	sort(a,a+N,comp);
	int cnt;
	int ans =0; int max;
	for(int i=0;i<N;i++){
		if(i==0||a[i]!=a[i-1]){
			cnt=i;
			max = a[i]; 
		}//ǰ����cnt��Ԫ�ش���a[i]��Ԫ�� 
		else if(a[i]==a[i-1]){
			cnt = i;
			max = a[i]-1;
		}//ǰ����cnt������a[i-1]��Ԫ�� 
		if(cnt<=max){//��cnt������a[i]��Ԫ�� 
			ans=cnt;
		}
		else break;
	}
	if(a[N-1]>N) ans=N; 
	cout<<ans<<endl;
	return 0;
}
