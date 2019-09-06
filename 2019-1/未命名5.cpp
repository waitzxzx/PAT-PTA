#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
using namespace std;
bool isPrime(int n){
	if(n<=1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(void){
	int N;cin>>N;bool isOK=false;
	if(isPrime(N)){
		if(isPrime(N-6)){
			isOK = true;
			cout<<"Yes"<<endl<<N-6<<endl;
		}
		else if(isPrime(N+6)){
			isOK = true;
			cout<<"Yes"<<endl<<N+6<<endl;
		} 
	}
	if(!isOK){
		cout<<"No"<<endl;
		for(int i=N+1;;i++){
			if((isPrime(i)&&isPrime(i-6))||(isPrime(i)&&isPrime(i+6))){
				cout<<i;
				break;
			}
		}
	}
	return 0;
}
