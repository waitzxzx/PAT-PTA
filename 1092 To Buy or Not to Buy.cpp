#include<iostream>
#include<string>
using namespace std;
int need[256]={0};
int own[256]={0};
int main(void){
	string s1,s2;cin>>s1>>s2;
	for(int i=0;i<s2.length();i++){
		need[s2[i]]++;
	}
	for(int i=0;i<s1.length();i++){
		own[s1[i]]++;
	}
	bool flag = true;
	int extra = 0;int missing=0;
	for(int i=0;i<256;i++){
		if(own[i]>=need[i]){
			extra += (own[i]-need[i]);
		}
		else{
			missing += (need[i]-own[i]);
			flag = false;
		}
	}
	if(flag) cout<<"Yes "<<extra<<endl;
	else cout<<"No "<<missing<<endl;
	return 0;
}
