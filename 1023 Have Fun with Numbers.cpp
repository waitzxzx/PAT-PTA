#include<iostream>
#include<string>
using namespace std;
const int N = 21;
int number[N];
int rec[10]={0};
int rec2[10]={0};
int main(void)
{
	string s;
	cin>>s;
	bool flag = true;
	//记录每个数字的个数，并且存入数组
	int len = s.length();
	int dlen;
	for(int i=len-1;i>=0;i--){
		int tmp = s[i]-'0';
		number[len-1-i] = tmp;
		rec[tmp]++;
	} 
	//大数加法
	int carry = 0;
	for(int i=0;i<len;i++){
		int tmp = carry+2*number[i];
		number[i] = tmp % 10;
		carry=tmp/10; 
	} 
	if(carry!=0){
		number[len]=carry;
		dlen = len+1;
		flag = false;
	}
	else dlen = len;
	for(int i=0;i<dlen;i++){
		rec2[number[i]]++;
	}
	for(int i=0;i<=9;i++){
		if(rec[i]!=rec2[i]){
			flag = false;
			break;
		}
	}
	if(!flag) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	for(int i=dlen-1;i>=0;i--) cout<<number[i];
	return 0;
}
