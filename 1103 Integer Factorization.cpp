#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
vector<int> v,ans,powV;
int N,K,P;//目标值、K个数的和、要求的幂
int bestSum = -1;
void init(){//对于不超过N的i的P次方 
	powV.push_back(0);
	while(pow(powV.size()*1.0,P*1.0)<N)
		powV.push_back(pow(powV.size()*1.0,P*1.0)); 
}
void dfs(int curK,int cnt,int curSum,int curPowSum){
	if(curPowSum>=N||cnt>=K){
		if(cnt==K&&curPowSum==N&&curSum>bestSum){ 
			bestSum = curSum;
			ans = v;
		}
		return;
	}
	if(curK>=1){
		v.push_back(curK);
		dfs(curK,cnt+1,curSum+curK,curPowSum+powV[curK]);
		v.pop_back();
		dfs(curK-1,cnt,curSum,curPowSum);
	}
}
int main(void){
	cin>>N>>K>>P;
	init();v.clear();
	dfs(powV.size()-1,0,0,0);
	if(ans.size()==0) cout<<"Impossible"<<endl;
	else{
		cout<<N<<" = ";
		for(int i=0;i<ans.size();i++){
			if(i==0) cout<<ans[i]<<"^"<<P;
			else cout<<" + "<<ans[i]<<"^"<<P;
		}
		cout<<endl;
	}
	return 0;
}
