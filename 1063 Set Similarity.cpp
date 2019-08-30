#include<iostream>
#include<set>
using namespace std;

int main(void){
	int N,K,M,a,b;
	cin>>N;
	set<int> sets[N+1];
	for(int i=1;i<=N;i++){
		cin>>M;
		for(int j=0;j<M;j++){
			cin>>a;
			sets[i].insert(a);
		}
	}
	cin>>K;
	set<int>::iterator it; 
	while(K--){
		cin>>a>>b;
		int cnt=0;//½»¼¯ÔªËØ
		for(it=sets[a].begin();it!=sets[a].end();it++){
			if(sets[b].find(*it)!=sets[b].end()) cnt++;
		} 
		double ans = 100.00*(double)cnt/double(sets[a].size()+sets[b].size()-cnt);
		printf("%.1f%%\n",ans);
	}
	
	return 0;
}
