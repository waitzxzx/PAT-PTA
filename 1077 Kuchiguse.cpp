#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(void){
	int n;
	cin>>n;getchar();
	string s, ans;
	for(int i=0;i<n;i++){
		getline(cin,s);
		reverse(s.begin(),s.end());
		if(i==0) ans =s;
		else{
			for(int j=0;j<ans.length();j++){
				if(s[j]!=ans[j]){
					ans = ans.substr(0,j);
					break;
				}
			} 
		}
	}
	if(ans.length()==0) cout<<"nai"<<endl;
	else{
		reverse(ans.begin(),ans.end());
	 	cout<<ans<<endl;
	
	}return 0;
}
