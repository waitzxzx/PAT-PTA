#include<iostream>
#define LL long long
using namespace std;
bool judge(LL a,LL b,LL c){
	LL sum = a+b;
	if(a>0&&b>0&&sum<0) return true;//正溢出
	else if(a<0&&b<0&&sum>=0) return false;//负溢出
	else if(sum>c) return true;//没有发生溢出
	else if(sum<=c) return false;//同上 
}
int main(void){
	int T;
	cin>>T;
	LL a,b,c;
	for(int i=0;i<T;i++){
		cin>>a>>b>>c;
		cout<<"Case #"<<i+1<<": ";
		if(judge(a,b,c)) cout<<"true"<<endl;
		else cout<<"false"<<endl;
	}
	return 0;
}
