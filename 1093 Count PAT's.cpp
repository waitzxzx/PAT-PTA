#include<iostream> 
#include<cstring>
using namespace std;
const int MOD = 1000000007;
const int LEN = 1e5+7;
int Pcnt[LEN]={0};
int Tcnt[LEN]={0};
int main(void){
	string s;cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='P'){
			if(i==0) Pcnt[i]=1;
			else Pcnt[i]=Pcnt[i-1]+1;
		}
		else{
			if(i==0) Pcnt[i]=0;
			else Pcnt[i]=Pcnt[i-1];
		}
		if(s[i]=='T'){
			if(i==0) Tcnt[i]=1;
			else Tcnt[i]=Tcnt[i-1]+1;
		}
		else{
			if(i==0) Tcnt[i]=0;
			else Tcnt[i]=Tcnt[i-1];
		}
	}
	int sum =0;
	for(int i=1;i<s.length()-1;i++){
		if(s[i]=='A'){
			sum = (sum+Pcnt[i-1]*(Tcnt[s.length()-1]-Tcnt[i]))%MOD;
		}
	}
	cout<<sum<<endl;
	return 0;
}
