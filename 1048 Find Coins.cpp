#include<iostream>
using namespace std;
const int MAX = 507;
int cnt[MAX]={0};
int main(void){
	int N,M,a;cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>a;
		cnt[a]++;
	}
	bool flag=false;
	for(int i=1;i<=M;i++){
		if(i+i==M){
			if(cnt[i]>=2){
				cout<<i<<" "<<i<<endl;
				flag=true;
				break;
			}
		}
		else{
			if(cnt[i]>=1&&M-i<=500&&cnt[M-i]>=1){
				cout<<i<<" "<<M-i<<endl;
				flag=true;
				break;
			}
		}
	}
	if(!flag) cout<<"No Solution"<<endl;
	return 0;
}
