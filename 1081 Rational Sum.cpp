#include<iostream>
#define ll long long
using namespace std;
ll numer[107],deno[107];//���ӣ���ĸ
ll c = 0; 
ll comfactor(ll a,ll b){//������ 
	if(a%b==0) return b;
	else return comfactor(b,a%b);
}
ll commul(ll a,ll b){//�󹫱��� 
	return a*b/comfactor(a,b);
}
void simplify(ll &num,ll &den){//���ٷ���ת��Ϊ�����������¼ϵ�� 
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
		simplify(numer[i],deno[i]);//���벢���� 
	}
	ll mul=1;
	for(int i=0;i<N;i++){
		mul =commul(mul,deno[i]);//������������֣������ĸ������������С��������ʽ�� 
	}
	ll num=0;
	for(int i=0;i<N;i++){
		num=num+numer[i]*(mul/deno[i]);//������С�������õ��ķ�ĸ������� 
	}
	simplify(num,mul);//���� 
	/*�����������֡��������������������*/ 
	if(c!=0) cout<<c;
	if(num!=0){
		if(c!=0) cout<<" ";
		cout<<num<<"/"<<mul;
	}
	if(c==0&&num==0) cout<<"0";
	cout<<endl;
	return 0;
}
