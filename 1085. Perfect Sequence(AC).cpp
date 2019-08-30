#include<iostream>
#include<algorithm> 
#define ll long long
using namespace std;
const int N  = 1e5+7;
ll a[N];
int main(void){
	int n;ll p;
	cin>>n>>p;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int maxLen = 0;
	for(int i=0;i<n;i++){
		int len = upper_bound(a+i+1,a+n,a[i]*p)-a-i;//二分查找降低复杂度 
		maxLen = max(len,maxLen);
	}
	cout<<maxLen<<endl;
	return 0; 
}
