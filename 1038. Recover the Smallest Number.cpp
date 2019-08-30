#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(string a,string b){
	return a+b<b+a;
}
vector<string> s;
int main(void){
	int n;string str,ans;
	cin>>n;
	while(n--){
		cin>>str;
		s.push_back(str);
	}
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<s.size();i++) ans+=s[i];
	while(ans.size()>0&&ans[0]=='0') ans.erase(ans.begin());
	if(ans.size()==0) cout<<"0"<<endl;
	else cout<<ans<<endl;
	return 0;
}
