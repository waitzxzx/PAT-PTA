#include<iostream>
#include<vector>
using namespace std;
bool mark[40]={false};
int sum(int n){
	int ans = 0;
	while(n){
		ans += n%10;
		n/=10;
	}
	return ans;
}
vector<int> v;
int main(void){
	int n,a;cin>>n;
	while(n--){
		cin>>a;
		mark[sum(a)]=true;
	}
	for(int i=0;i<37;i++){
		if(mark[i]) v.push_back(i);
	}
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++){
		if(i==0) cout<<v[i];
		else cout<<" "<<v[i];
	} 
	return 0;
}
