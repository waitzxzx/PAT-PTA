#include<iostream>
#include<cstring>
using namespace std;
string int2string(int n){
	string ans ="";
	do{
		ans = char(n%10+'0')+ans;
		n/=10;
	}while(n);
	return ans;
}
string nextString(string s){
	int cnt=0;string ans = "";
	for(int i=0;i<s.length();i++){
		if(i==0) cnt=1;
		else{
			if(s[i]==s[i-1]){
				cnt++;
			} 
			else{
				ans += s[i-1];
				ans += int2string(cnt);
				cnt=1;
			}
		}
	}
	ans+= s[s.length()-1];
	ans+= int2string(cnt);
	return ans;
}
int main(void){
	string s;int N;cin>>s>>N;
	if(N>=2){
		for(int i=0;i<N-1;i++){
			s = nextString(s);
		}
	} 
	cout<<s<<endl;
	return 0;
}
