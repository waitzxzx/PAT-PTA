#include<iostream>
#define ll long long
using namespace std;
const int N  = 1e5+7;
int a[N];
int main(void){
	int n;ll p;
	cin>>n>>p;
	for(int i=0;i<n;i++) cin>>a[i];
	int cnt = 0;int ans = 0;
	for(int i=0;i<n;i++){
		ll m = a[i];cnt=0;
		for(int j=0;j<n;j++){
			ll M = a[j];
			if(M<=p*m&&M>=m) cnt++;
		}
		if(cnt>ans) ans=cnt;
	}
	cout<<ans<<endl;
	return 0;
}
