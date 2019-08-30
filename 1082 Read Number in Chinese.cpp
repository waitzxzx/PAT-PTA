#include<iostream>
using namespace std;
string words[110];
string digit[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int idx = 0;
void read(int n){
	int thousand,hundred,tens,ones;
	thousand = n/1000;
	n = n - thousand*1000;
	hundred = n/100;
	n = n - hundred*100;
	tens = n / 10;
	ones = n % 10;
	bool flag=false;
	if(thousand!=0){
		words[idx++]=digit[thousand];
		words[idx++]="Qian";
		if(hundred==0&&(tens>0||ones>0)){
			words[idx++]=digit[0]; 
		}
	}
	if(hundred!=0){
		words[idx++]=digit[hundred];
		words[idx++]="Bai";
		if(tens==0&&ones>0) words[idx++]=digit[0];
	}
	if(tens!=0){
		flag=false;
		words[idx++]=digit[tens];
		words[idx++]="Shi";
	}
	if(ones!=0) words[idx++]=digit[ones];
}
int main(void){
	int n;cin>>n;
	if(n<0) {
		words[idx++]="Fu";
		n=-n;
	}
	if(n==0) words[idx++]=digit[0];
	int hm=0,tt=0;
	if(n>=100000000){
		hm = n/100000000;
		words[idx++]=digit[hm];
		words[idx++]="Yi";
		n = n-hm*100000000;
	}
	if(n>=10000){
		tt = n/10000;
		if(hm>0&&tt<1000&&tt>0) words[idx++]=digit[0];//Ç°ÖÃ0 
		read(tt);
		words[idx++]="Wan";
		n = n-tt*10000;
	}
	if(n>0){
		if((tt>0||hm>0)&&n<1000&&n>0) words[idx++]=digit[0];
		read(n);
	}
	for(int i=0;i<idx;i++){
		if(i==0) cout<<words[i];
		else cout<<" "<<words[i];
	}
	cout<<endl;
	return 0;
}
