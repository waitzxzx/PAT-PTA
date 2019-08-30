#include<iostream>
#include<string>
#define max 107
using namespace std;
string to_String(int n)//intתstring�������� 
{
	if(n==0) return "0";
    int m = n;
    char s[max];
    char ss[max];
    int i=0,j=0;
    if (n < 0)// ������
    {
        m = 0 - m;
        j = 1;
        ss[0] = '-';
    }    
    while (m>0)
    {
        s[i++] = m % 10 + '0';
        m /= 10;
    }
    s[i] = '\0';
    i = i - 1;
    while (i >= 0)
    {
        ss[j++] = s[i--];
    }    
    ss[j] = '\0';    
    return ss;
}
bool isZero(string s){
	for(int i=0;i<s.length();i++){
		if(s[i]!='0'&&s[i]!='.') return false;
	}
	return true;
}
string notation(string s,int n){
	if(isZero(s)){
		string ans = ""; 
		for(int i=0;i<n;i++) ans+='0'; 
		ans =  "0."+ans+"*10^0";
		return ans;
	}
	while(s.length()>0&&s[0]=='0'){
		s.erase(s.begin());//ȥ��s��ǰ��0 
	}
	if(s[0]=='.') s='0'+s;//���ֱ�Ӿ���С���㣬Ϊ����0 
	//�õ���Чλ 
	string sig = "";int idx = 0;
	bool start = false;
	for(int i=0;i<s.length()&&idx<n;i++){
		if(s[i]=='.') continue;
		if(!start&&s[i]>'0'&&s[i]<='9') start=true;
		if(start){
			sig += s[i];idx++;
		}
	}
	while(idx<n){
		sig=sig+"0";idx++;
	}
	int exp=0;string ans="";
	if(s.find('.')!=s.npos){//��С�� 
		if(s[0]=='0'){//��0.xxx����ʽ���ж�0.�Ժ��ж��ٸ�0 
			bool hasPoint = false;
			for(int i=0;i<s.length();i++){
				if(!hasPoint&&s[i]=='.'){
					hasPoint = true;
					continue;
				} 
				if(hasPoint){
					if(s[i]=='0') exp--;
					else break;
				}
			}
		}
		else{//��xx.xx��ʽ���ж����������ж���λ 
			exp = s.find('.');
		}
	}
	else{//����С�� 
		exp	= s.length(); 
	}
	ans =  "0."+sig+"*10^"+to_String(exp);
	return ans;
}
int main(void){
	string s1,s2;int n;cin>>n>>s1>>s2;
	s1 = notation(s1,n);
	s2 = notation(s2,n);
	if(s1==s2){
		cout<<"YES"<<" "<<s1<<endl;
	}
	else{
		cout<<"NO"<<" "<<s1<<" "<<s2<<endl;
	}
	return 0;
}
