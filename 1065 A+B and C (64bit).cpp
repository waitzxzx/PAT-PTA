#include<iostream>
#define LL long long
using namespace std;
bool judge(LL a,LL b,LL c){
	LL sum = a+b;
	if(a>0&&b>0&&sum<0) return true;//�����
	else if(a<0&&b<0&&sum>=0) return false;//�����
	else if(sum>c) return true;//û�з������
	else if(sum<=c) return false;//ͬ�� 
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
