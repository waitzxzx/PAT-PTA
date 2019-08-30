#include<iostream>
#include<cstring>
using namespace std;
int* conv(int n,int a[],int m){//n to m
	string ans="";
	int len = num.size();
	for(int i=0;i<len;){
		int remain = 0;
		for(int j=i;j<len;j++){
			int temp;
			if(num[j]>='0'&&num[j]<='9') temp = remain*n+num[j]-'0';
			else temp = remain*n+num[j]+'a'-10;
			int temp2 = temp / m;
			if(temp2>=0&&temp2<=9) num[j]=temp2+'0';
			else num[j]=temp2+'a'
			num[j] = temp / m+'0';
			remain = temp % m;
		}
		if(remain>=0&&remain<=9) ans=+char(remain+'0');
		else ans+=char(remain+'a'-10);
		while(num[i]=='0') i++;
	}
	return ans;
}
int main(void){
	string N1,N2;
	int tag,radix;
	cin>>N1>>N2>>tag>>radix; 
	bool flag = false;
	if(tag==1){
		string n1_s = conv(radix,N1,10);
		for(int i=2;i<=36;i++){
			string temp = conv(i,N2,10); 
			if(temp==n1_s){
				flag=true;
				cout<<i;
				break;
			}
		}
		if(!flag) cout<<"Impossible";
	}
	if(tag==2){
		string n2_s = conv(radix,N2,10);
		for(int i=2;i<36;i++){
			string temp = conv(i,N1,10); 
			if(temp==n2_s){
				flag=true;
				cout<<i;
				break;
			}
		}
		if(!flag) cout<<"Impossible";
	}
	return 0;
}
