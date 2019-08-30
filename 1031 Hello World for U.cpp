#include<bits/stdc++.h>
using namespace std;
char arr[30][30];
int main(void)
{
	string s;cin>>s;
	memset(arr,' ',sizeof(arr));
	int len = s.length();
	int side;
	if(len%3==0)side=len/3-1;
	else side = len/3;
	int mid = len-2*side;
	int count=0;
	for(int i=0;i<side;i++){
		arr[i][0]=s[count++];
	}
	for(int j=0;j<mid;j++){
		arr[side][j]=s[count++];
	}
	for(int i=side-1;i>=0;i--){
		arr[i][mid-1]=s[count++];
	}
	for(int i=0;i<side+1;i++){
		for(int j=0;j<mid;j++){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	return 0;
}
