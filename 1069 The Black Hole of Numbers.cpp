#include<iostream>
#include<string>
using namespace std;
int reverse(int n){
	int ans = 0;
	for(int i=0;i<4;i++){
		ans = ans * 10+n%10;
		n/=10;
	}
	return ans;
}
int sort(int n){//non-decrease
	int digit[10]={0};
	for(int i=0;i<4;i++){
		digit[n%10]++;
		n/=10;
	}
	int ans = 0;
	for(int i=9;i>=0;i--){
		while(digit[i]--){
			ans = ans*10+i;
		}
	}
	return ans;
}
int main(void){
	int n;cin>>n;
	int res;
	while(true){
		int a1 = sort(n);
		int a2 = reverse(a1);
		res = a1 - a2;
		printf("%04d - %04d = %04d\n",a1,a2,res);
		if(res==0||res==6174)  break;
		n = res; 
	}
	return 0;
}
