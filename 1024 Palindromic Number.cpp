#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isPal(string s){
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-1-i]) return false;
	}
	return true;
}
string add(string s){
	string res = ""; 
	int carry = 0;
	int len = s.length();
	for(int i=0;i<len;i++){
		int temp = (s[i]-'0')+(s[len-1-i]-'0')+carry;
		res += temp%10+'0';
		carry = temp/10; 
	}
	if(carry!=0) res+= carry+'0';
	reverse(res.begin(),res.end());//живЊ 
	return res;
}
int main(void){
	string N;
	int K;
	cin>>N>>K;
	bool flag = false;
	int i=0;
	//while(i<K){
	//	if(isPal(N)){
	//		cout<<N<<endl<<i<<endl;
	//		flag=true;
	//		break;
	//	}
	//	N = add(N);
	//	i++;
	//}
	for(int i=0;i<K;i++){
		if(isPal(N)){
			flag = true;
			cout<<N<<endl<<i<<endl;
			break;
		} 
		N = add(N);
	}
	if(!flag) cout<<N<<endl<<K<<endl;
	return 0;
}
