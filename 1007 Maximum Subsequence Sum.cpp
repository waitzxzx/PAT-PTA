#include<iostream>
using namespace std;
const int MAX = 1e5+7;
int a[MAX]={0};
int main(void){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	int startIdx=0,endIdx=0,maxStart=0,maxEnd=0;
	int curMax = a[0];
	int max = a[0];
	for(int i=1;i<n;i++){
		if(curMax>0){
			curMax+=a[i];
			endIdx=i;
		}
		else{
			curMax=a[i];
			startIdx=i;
			endIdx=i;
		}
		if(curMax>max){
			maxStart=startIdx;
			maxEnd=endIdx;
			max=curMax;
		}
	}
	if(max<0){
		cout<<"0 "<<a[0]<<" "<<a[n-1]<<endl;
	}
	else{
		cout<<max<<" "<<a[maxStart]<<" "<<a[maxEnd]<<endl;
	}
	return 0;
	
} 
