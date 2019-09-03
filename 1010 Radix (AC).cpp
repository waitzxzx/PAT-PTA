#include<iostream> 
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
ll char2digit(char c){
	if(c>='0'&&c<='9') return c-'0';
	else return c-'a'+10;
}
ll toDec(string s,ll radix){
	ll ans = 0;
	for(int i=0;i<s.length();i++){
		ans=radix*ans+char2digit(s[i]);
		if(ans<0) return -1; 
	}
	return ans;
}
int main(void){
	string n1,n2;int tag,radix;
	cin>>n1>>n2>>tag>>radix;
	if(tag==2) swap(n1,n2);
	ll mid,left,right,target;
	target = toDec(n1,radix);//把目标数转换成十进制
	left = 2;
	for(int i=0;i<n2.size();i++) left = max(left,1+char2digit(n2[i]));
	right = max(left,target);
	while(left<=right){
		mid = (left+right)>>1;
		ll temp = toDec(n2,mid);
		if(temp>=target||temp==-1)//根据当前进制转换的数过大
			right = mid-1;
		else//反之 
			left =  mid+1;
	} 
	if(toDec(n2,left)==target) cout<<left<<endl;//验证 
	else cout<<"Impossible"<<endl;
	return 0;
}
