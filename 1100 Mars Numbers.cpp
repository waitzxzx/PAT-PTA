#include<iostream>
#include<string> 
using namespace std;
string lowDigit[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov","dec"};
string highDigit[13]={" ","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int mar2earth(string s){
	if(s.length()<=4){
		for(int i=0;i<13;i++){
			if(s==lowDigit[i]) return i;
			if(s==highDigit[i]) return i*13;
		}
	}
	else{
		string low_str = s.substr(4,s.size()-4);
		string high_str = s.substr(0,3);
		int low,high;
		for(int i=0;i<13;i++){
			if(low_str==lowDigit[i]){
				low = i;break;
			}
		}
		for(int i=1;i<13;i++){
			if(high_str==highDigit[i]){
				high = i;break;
			}
		} 
		return high*13+low;
	}
}
string earth2mar(int n){
	string ans = "";
	if(n<=12) ans=lowDigit[n];
	else if(n%13==0) ans = highDigit[n/13];
	else{
		ans+=highDigit[n/13];
		ans+=" ";
		ans+=lowDigit[n%13];
	}
	return ans;
}
int string2int(string s){
	if(s.length()==1) return s[0]-'0';
	else if(s.length()==2) return 10*(s[0]-'0')+(s[1]-'0');
	else return 100*(s[0]-'0')+10*(s[1]-'0')+s[2]-'0';
}
int main(void){
	int N;string s;
	cin>>N;getchar();
	while(N--){
		getline(cin,s);
		if(s[0]>'9'||s[0]<'0') cout<<mar2earth(s)<<endl;
		else{
			cout<<earth2mar(string2int(s))<<endl;
		}
	}
	return 0;
}
