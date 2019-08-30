#include<iostream>
#include<cmath>
using namespace std;
int main(void){
	int N; cin>>N;
	int ans=0,start;
	int m = sqrt(1.0*N);
	for(int i=2;i<=m;i++){
		int num = N,a = i;
		int len = 0;
		while(num>=a&&num%a==0){
			num/=a;
			len++;a++;
		}
		if(len>ans){
			ans=len;start=i;
		}
	}
	if(ans==0) cout<<"1"<<endl<<N<<endl;
	else{
		cout<<ans<<endl;
		for(int i=start;i<start+ans;i++){
			if(i==start) cout<<i;
			else cout<<"*"<<i;
		}
		cout<<endl;
	} 
	return 0;
}
