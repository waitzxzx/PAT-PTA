#include<iostream>
#define LL long long 
using namespace std;
const int N = 1e4+7; 
bool mark[N]={false};
int prime[N];
int exp[N]={0};
int primeCount=0;
void init(){
	for(int i=2;i<N;i++){
		if(mark[i]) continue;
		for(int j=i*i;j<N;j=j+i){
			mark[j]=true;
		}
	}
	for(int i=2;i<N;i++){
		if(!mark[i]) prime[primeCount++]=i;
	}
	//for(int i=0;i<primeCount;i++) cout<<prime[i]<<endl;
}
int main(void){
	init();
	LL N,NUM;
	cin>>NUM;
	N=NUM;
	int idx = 0;
	while(N!=1){
		//cout<<N<<endl;
		if(N%prime[idx]==0){
			while(N%prime[idx]==0){
				N=N/prime[idx];
				exp[idx]++;
			}
		}
		idx++;
		if(idx>=primeCount) break;
	} 
	if(N!=1) {
		prime[primeCount]=N;
		exp[primeCount]=1;
		primeCount++;
	}
	cout<<NUM<<"=";
	bool flag = false;
	for(int i=0;i<idx;i++){
		if(exp[i]!=0){
			if(flag) cout<<"*";
			flag=true;
			if(exp[i]==1) cout<<prime[i];
			else cout<<prime[i]<<"^"<<exp[i];
		}
	}
	if(N!=1) cout<<"*"<<N;
	if(NUM==1) cout<<"1";
	cout<<endl;
	return 0;
}
