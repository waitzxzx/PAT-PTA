#include<iostream>
using namespace std;
const int MAX = 1e5+7;
int a[MAX]={0};
int main(void){
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		a[m]++;
	}
	for(int i=1;i<MAX;i++){
		if(a[i]==0){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
