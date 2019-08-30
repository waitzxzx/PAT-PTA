#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 1000007;
int arr[MAX]={0};
bool cmp(int a,int b){
	return a<b;
}
int main(void)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n,cmp);
	int idx = 0;
	while(arr[idx]<=0) idx++;
	for(int i=1;;){
		if(idx<n&&i==arr[idx]){
			while(idx<n&&i==arr[idx]){
				idx++;
			}
			i++;
		}
		else{
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
