#include<iostream>
#include<cstring>
using namespace std;
string digit[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int arr[30];
int main(void)
{
	string in;
	cin>>in;
	int sum = 0;
	for(int i=0;i<in.length();i++){
		sum=sum+in[i]-'0';
	}
	int index = 0;
	do{
		int d = sum%10;
		arr[index] = d;
		index++;
		sum/=10;
	}while(sum>0);
	for(int i=index-1;i>=0;i--){
		if(i==0) cout<<digit[arr[i]].c_str();
		else cout<<digit[arr[i]].c_str()<<" ";
	}
	cout<<endl;
	return 0;
 } 
