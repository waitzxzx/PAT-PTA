#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(void){
	string s;getline(cin,s);
	int maxLen = 1; 
	for(int i=0;i<s.length();i++){
		for(int j=i+1;j<=s.length();j++){
			if(j-i>maxLen){
				string sub = s.substr(i,j-i);
				string origin = sub;
				reverse(sub.begin(),sub.end()); 
				if(origin == sub){
					maxLen = j-i;
				}
			}
		}
	}
	cout<<maxLen<<endl;
	return 0;
}
