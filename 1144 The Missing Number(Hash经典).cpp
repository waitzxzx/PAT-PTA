//18
#include<iostream>
using namespace std;
const int MAX = 0xffffffff;
int a[MAX]={0};
int main(void){
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		if(m>0) a[m]++;
	}
	for(int i=1;i<MAX;i++){
		if(a[i]==0){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
