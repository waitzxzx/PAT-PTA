#include<iostream>
#include<cstring>
using namespace std;
bool isPrime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
const int MAX = 1e5+13;
int table[MAX]={0};
int main(void){
	int Msize,N,M;cin>>Msize>>N>>M;
	while(!isPrime(Msize)) Msize++;
	int key,q;
	while(N--){
		cin>>key;bool isOk=false;
		for(int i=0;i<Msize;i++){
			if(table[(key+i*i)%Msize]==0){
				table[(key+i*i)%Msize]=key;
				isOk = true;
				break;
			}
		}
		if(!isOk) cout<<key<<" cannot be inserted."<<endl;
	}
	int sum=0;
	for(int i=0;i<M;i++){
		cin>>q;
		for(int k=0;k<=Msize;k++){
			int npos = (q+k*k)%Msize;
			if(table[npos]==0||table[npos]==q||k==Msize){
				//cout<<k+1<<endl; 
				sum+=(k+1);
				break;
			}
		}
	}
	printf("%.1f\n",double(sum)/double(M));
	return 0;
} 
