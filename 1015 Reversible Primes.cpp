#include<iostream>
using namespace std;
int reverse(int n,int d){//reverse any number with d redix
	int ans = 0;
	while(n){
		ans = ans*d+n%d;
		n/=d;
	}
	return ans;
}
bool isPrime(int x){//judge if it is a prime number
	if(x<2) return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}
int main(void){
	int n,d;
	while(cin>>n){
		if(n<0) break;
		cin>>d;
		//cout<<n1<<" "<<n2<<endl;
		if(isPrime(n)&&isPrime(reverse(n,d)))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
