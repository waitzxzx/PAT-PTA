#include<iostream>
#define ll long long
using namespace std;
ll numer[107],deno[107];//分子，分母
ll c = 0; 
ll comfactor(ll a,ll b){//求公因数 
	if(a%b==0) return b;
	else return comfactor(b,a%b);
}
ll commul(ll a,ll b){//求公倍数 
	return a*b/comfactor(a,b);
}
void simplify(ll &num,ll &den){//将假分数转化为真分数，并记录系数 
	ll coe = num/den; c+=coe;
	num -= den*coe;
	if(num==0){
		den=1;return;
	}
	ll cf = comfactor(num,den);
	num/=cf;den/=cf;
}
int main(void){
	int N;cin>>N;
	for(int i=0;i<N;i++){
		scanf("%lld/%lld",&numer[i],&deno[i]);
		simplify(numer[i],deno[i]);//读入并化解 
	}
	ll mul=1;
	for(int i=0;i<N;i++){
		mul =commul(mul,deno[i]);//根据真分数部分，求出分母（反复采用最小公倍数公式） 
	}
	ll num=0;
	for(int i=0;i<N;i++){
		num=num+numer[i]*(mul/deno[i]);//根据最小公倍数得到的分母计算分子 
	}
	simplify(num,mul);//化解 
	/*根据整数部分、分数部分情况，输出结果*/ 
	if(c!=0) cout<<c;
	if(num!=0){
		if(c!=0) cout<<" ";
		cout<<num<<"/"<<mul;
	}
	if(c==0&&num==0) cout<<"0";
	cout<<endl;
	return 0;
}
