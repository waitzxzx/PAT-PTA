#include<iostream>
#include<algorithm>
using namespace std;
struct mooncake{
	double amount,price,ratio;
	bool operator < (const mooncake &other) const{
		return ratio>  other.ratio;
	}
	void calRatio(){
		ratio = price / amount;
	}
};
mooncake M[1007];
int main(void){
	int N;double D;
	cin>>N>>D;
	for(int i=0;i<N;i++) cin>>M[i].amount;
	for(int i=0;i<N;i++) cin>>M[i].price;
	for(int i=0;i<N;i++) M[i].calRatio();
	double cur = 0.0;int idx=0;double ans =0.0;
	sort(M,M+N);
	while(cur<D&&idx<N){
		if(D-cur>=M[idx].amount){
			ans+=M[idx].price;
			cur+=M[idx].amount;
		}
		else{
			ans+=(D-cur)*M[idx].ratio;
			cur = D;
		}
		idx++;
	}
	printf("%.2f\n",ans);
	return 0;
	
	
}
