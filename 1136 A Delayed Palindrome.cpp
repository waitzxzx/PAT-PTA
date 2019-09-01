#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool isPal(string s){
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-1-i]) return false;
	}
	return true;
}
string add(string a){
	string b = a;
	reverse(a.begin(),a.end());
	int carry=0;
	string ans="";
	for(int i=0;i<a.length();i++){
		int c = a[i]-'0'+b[i]-'0'+carry;
		carry = c/10;
		ans+=char(c%10 +'0');
	}
	if(carry!=0) ans+=char(carry+'0');
	reverse(ans.begin(),ans.end());
	cout<<b<<" + "<<a<<" = "<<ans<<endl;
	return ans;
}
int main(void){
	string s;cin>>s;
	bool flag = false;
	for(int i=0;i<10;i++){
		if(isPal(s)){//先判断是否回文 
			flag = true;
			cout<<s<<" is a palindromic number."<<endl;
			break;
		}
		s = add(s);
	}
	if(!flag) cout<<"Not found in 10 iterations."<<endl;
	return 0;
}
