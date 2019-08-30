#include<iostream>
using namespace std;
int a[101],b[101];
int dec2b(int n,int base,int arr[]){
	int idx=0;
	while(n!=0){
		arr[idx]=n%base;
		n/=base;
		idx++;
	}
	return idx;
}
int b2dec4rev(int arr[],int base,int len){
	int ans=0;
	for(int i=0;i<len;i++){
		ans=ans*base+arr[i];
	}
	return ans;
}
int main(void){
	int n,base;
	cin>>n>>base;
	int len=dec2b(n,base,a);
	int reverse = b2dec4rev(a,base,len);
	if(n==reverse) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	for(int i=len-1;i>=0;i--){
		if(i==len-1) cout<<a[i];
		else cout<<" "<<a[i]; 
	}

	return 0;
	
}
