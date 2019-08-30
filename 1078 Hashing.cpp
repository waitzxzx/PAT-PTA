#include<iostream>
using namespace std;
const int N = 10013;
bool mark[N]={false};
int prime[N];
int ht[N];
int index = 0;
void init(){
	for(int i=2;i<N;i++){
		if(mark[i]) continue;
		for(int j=i*i;j<N;j=j+i){
			mark[j]=true;
		}
	}
	for(int i=2;i<N;i++){
		if(!mark[i]) prime[index++]=i;
	} 
}
int main(void){
	init();
	int M,N,size,key;
	cin>>M>>N;
	for(int i=0;i<index;i++){
		if(prime[i]>=M){
			size = prime[i];break;
		} 
	} 
	for(int i=0;i<size;i++) ht[i]=-1;
	for(int i=0;i<N;i++){
		cin>>key;
		if(i!=0) cout<<" ";
		int pos = key%size;
		if(ht[pos]==-1){//hash表该项为空 
			ht[pos]=key;
			cout<<pos;
		}
		else{//发生冲突，线性平方探测
			bool flag =false;
			for(int i=1;i<=size-1;i++){
				int npos = (key+i*i)%size; 
				if(ht[npos]==-1){
			 		cout<<npos;
					ht[npos]=key;
			 		flag=true;
					break;
				}
			}
			if(!flag) cout<<"-";
		}
	}
	return 0;
}
