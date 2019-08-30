#include<iostream>
#include<string>
using namespace std;
int modified = 0;
bool mark[1001];
struct record{
	string user,passwd;
};
record r[1001];
bool judge(string &input){
	bool flag = false;
	for(int i=0;i<input.length();i++){
		if(input[i]=='1'){
			input[i]='@';flag=true;
		} 
		if(input[i]=='0'){
			input[i]='%';flag=true;
		}
		if(input[i]=='l'){
			input[i]='L';flag=true;
		}
		if(input[i]=='O'){
			input[i]='o';flag=true;
		}
	}
	if(flag) modified++;
	return flag;
}
int main(void){
	int M;cin>>M;
	for(int i=0;i<M;i++){
		mark[i]=false;
		cin>>r[i].user>>r[i].passwd;
		if(judge(r[i].passwd)) mark[i]=true;
	}
	if(modified!=0){
		cout<<modified<<endl;
		for(int i=0;i<M;i++){
			if(mark[i]) cout<<r[i].user<<" "<<r[i].passwd<<endl;
		}
	}
	else{
		if(M==1) cout<<"There is 1 account and no account is modified"<<endl;
		else cout<<"There are "<<M<<" accounts and no account is modified"<<endl;
	}
	return 0;
}
