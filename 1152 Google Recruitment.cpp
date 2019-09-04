#include<iostream>
#include<cstring>
using namespace std;
string s,num;int L,K;
bool isPrime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int string2int(string s){
	int ans = 0;
	for(int i=0;i<s.length();i++){
		ans = ans*10+s[i]-'0';
	}
	return ans;
}
int main(void){
	cin>>L>>K>>s;
	for(int i=0;i+K<=s.length();i++){
		num = s.substr(i,K);
		int x = string2int(num);
		if(isPrime(x)){
			cout<<num<<endl;
			return 0;
		} 
	}
	cout<<"404"<<endl;
	return 0;
}
