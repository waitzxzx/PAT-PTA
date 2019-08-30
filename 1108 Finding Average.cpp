#include<iostream>
#include<cstring>
using namespace std;
bool isLegal(string s,double &n){
	n=0;
	bool isNeg = false;
	if(s[0]=='-'){
		isNeg = true;
		s.erase(s.begin());
	}
	bool hasPoint = false;
	int in = 0;
	double p=0;
	int cnt=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(!hasPoint) in=10*in+(s[i]-'0');
			else if(hasPoint&&cnt<2){
				cnt++;
				if(cnt==1) p = 0.1*(s[i]-'0');
				else if(cnt==2) p+=0.01*(s[i]-'0');
			}
			else return false;
		}
		else if(in!=0&&s[i]=='.'&&!hasPoint) hasPoint = true;
		else return false;
	}
	if(isNeg) n = -p-in;
	else n = p+in;
	if(n<=1000.0&&n>=-1000.0) return true;
	else return false;
}
int main(void){
	int N;cin>>N;
	int cnt = 0;double sum = 0;
	string s;double x;
	for(int i=0;i<N;i++){
		cin>>s;
		if(isLegal(s,x)){
			cnt++;
			sum+=x;
		}
		else{
			cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
		}
	}
	if(cnt==1) cout<<"The average of "<<cnt<<" number is ";
	else cout<<"The average of "<<cnt<<" numbers is ";
	
	if(cnt==0) cout<<"Undefined"<<endl;
	else {
		printf("%.2f\n",sum/cnt);
	}
} 
