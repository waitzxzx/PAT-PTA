#include<iostream>
#include<string>
using namespace std;
string weekday[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(void){
	int w,h,m;
	string s1,s2;
	cin>>s1>>s2;
	int cnt=0;
	for(int i=0;i<s1.length()&&i<s2.length();i++){
		if(s1[i]==s2[i]){
			if(cnt==0&&s1[i]>='A'&&s1[i]<='G'){
				w = s1[i]-'A';
				cnt++; 
			}
			else if(cnt==1&&((s1[i]>='0'&&s1[i]<='9')||(s1[i]>='A'&&s1[i]<='N'))){
				if(s1[i]>='0'&&s1[i]<='9') h = s1[i]-'0';
				else  h = 10+s1[i]-'A';
				break;
			} 
		}
	}
	cin>>s1>>s2;
	for(int i=0;i<s1.length()&&i<s2.length();i++){
		if(s1[i]==s2[i]&&((s1[i]>='A'&&s1[i]<='Z')||(s1[i]>='a'&&s1[i]<='z'))){
			m = i;break;
		}
	}
	printf("%s %02d:%02d\n",weekday[w].c_str(),h,m);
	return 0;
}
