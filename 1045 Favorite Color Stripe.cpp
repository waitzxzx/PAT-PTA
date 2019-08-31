#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 1e4+7;
int priority[207]={0};
int a[MAX];
int dp[MAX]={0};//以位置i结束的最长串 
int main(void){
	int N,M,L,x;cin>>N>>M;//total colors, favorite order
	for(int i=1;i<=M;i++){
		cin>>x;
		priority[x]=i;//优先级，正数且优先级越小越高 
	}
	cin>>L; 
	for(int i=0;i<L;i++) cin>>a[i];
	int maxLen=0; 
	for(int i=0;i<L;i++){
		if(priority[a[i]]>0){
			for(int j=0;j<i;j++){
				if(priority[a[j]]>0&&priority[a[j]]<=priority[a[i]]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
			dp[i]=max(1,dp[i]);
			maxLen = max(maxLen,dp[i]);
		}
	} 
	cout<<maxLen<<endl; 
	return 0;
} 
