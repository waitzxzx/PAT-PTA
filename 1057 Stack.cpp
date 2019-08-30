#include<iostream>
#include<string>
using namespace std;
const int MAX = 1e5+7;
int cnt [MAX] = {0};
int st[MAX];
int size = 0;
int string2int(string s){
	int ans = 0;
	for(int i=0;i<s.length();i++){
		ans = ans*10+s[i]-'0';
	}
	return ans;
}
int PeekMedian(){
	int mid = (size+1)/2;
	int num =0;
	for(int i=0;i<MAX;i++){
		if(cnt[i]>0){
			num+=cnt[i];
			if(num>=mid) return i;
		}
	}
}
int main(void){
	int n;cin>>n;getchar();
	string s;
	while(n--){
		getline(cin,s);
		if(s=="Pop"){
			if(size>0){
				int top = st[size-1];
				cout<<top<<endl;
				cnt[top]--;
				size--;
			}
			else cout<<"Invalid"<<endl; 
		}
		else if(s=="PeekMedian"){
			if(size==0) cout<<"Invalid"<<endl; 
			else cout<<PeekMedian()<<endl;
		}
		else{
			s = s.substr(5);
			int elem = string2int(s);
			cnt[elem]++;
			size++;
			st[size-1] = elem;
		}
	}
	return 0;
}
