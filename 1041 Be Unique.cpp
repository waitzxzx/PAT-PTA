#include<iostream>
using namespace std;
const int N = 1e4+1;
const int M = 1e5+7;
int cnt[N]={0};
int a[M];
int main(void)
{
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];cnt[a[i]]++;
	}
	int ans = -1;
	for(int i=0;i<n;i++){
		if(cnt[a[i]]==1){
			ans = a[i];break;
		}
	}
	if(ans==-1) cout<<"None"<<endl;
	else cout<<ans<<endl;
	return 0;
}
