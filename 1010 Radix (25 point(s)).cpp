#include<iostream>
#include<cstring>
using namespace std;
string conv(int n,string num,int m){//n to m
	string ans="";
	int len = num.length();
	for(int i=0;i<len;){
		int remain = 0;
		for(int j=i;j<len;j++){
			if(num[j]>='0'&&num[j]<='9') remain = n*remain+num[j]-'0';
			else remain=n*remain+num[j]-'a'+10;
			int temp = remain/m;
			if(temp>=0&&temp<=9) num[j]=temp+'0';
			else num[j]=temp-10+'a';
			remain=remain%m;
		}
		if(remain>=0&&remain<=9) ans=char(remain+'0')+ans;
		else ans = char(remain+'a'-10)+ans;
		while(num[i]=='0')i++;
	}
	return ans;
}
int main(void){
	string N1,N2;int tag,radix;
	cin>>N1>>N2>>tag>>radix; 
	bool flag = false;
	if(tag==1){
		for(int i=2;i<=36;i++){
			if(conv(radix,N1,i)==N2){
				flag=true;
				cout<<i<<endl;
				break;
			}
		}
	}
	else if(tag==2){
		for(int i=2;i<=36;i++){
			if(conv(radix,N2,i)==N1){
				flag=true;
				cout<<i<<endl;
				break;
			}
		}
	}
	if(!flag) cout<<"Impossible"<<endl;
	return 0;
}
