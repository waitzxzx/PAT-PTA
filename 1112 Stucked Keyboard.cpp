#include<iostream>
#include<cstring>
using namespace std;
bool broken[256];
bool output[256];
int main(void){
	int k;string s;cin>>k>>s;
	int cnt;
	for(int i=0;i<256;i++){
		broken[i]=true;
		output[i]=false;
	} 
	for(int i=0;i<s.length();i++){
		if(i==0) cnt=1;
		else if(i>0&&s[i]==s[i-1]) cnt++;
		else{
			if(cnt%k!=0) broken[s[i-1]]=false;
			cnt=1;
		}
	}
	if(cnt%k!=0) broken[s[s.length()-1]]=false;
	for(int i=0;i<s.length();i++){
		if(broken[s[i]]&&!output[s[i]]){
			cout<<s[i];
			output[s[i]]=true;
		}
	}
	cout<<endl;
	for(int i=0;i<s.length();){
		cout<<s[i];
		if(broken[s[i]]) i+=k;
		else i++;
	}
	return 0;
} 
