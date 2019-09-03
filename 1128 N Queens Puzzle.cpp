#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1005];
bool judge(int n,int a[]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				if(a[i]==a[j]) return false;
				if(abs(i-j)==abs(a[i]-a[j])) return false;
			}
		}
	}
	return true;
}
int main(void){
	int N,k;cin>>N;
	while(N--){
		cin>>k;
		for(int i=0;i<k;i++) cin>>a[i];
		if(judge(k,a)) puts("YES");
		else puts("NO");
	}
	return 0;
}
