#include<iostream>
#include<cstring>
#include<vector> 
using namespace std;
vector<pair<int,int> > v;
const int MAX = 1e5+7;
bool mark[MAX]={false};
int main(void){
	int N,M,a,b;cin>>N;
	while(N--){
		cin>>a>>b;
		v.push_back(pair<int,int>(a,b));
	}
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>a;mark[a]=true;
	}
	for(auto i :v){
		if(mark[i.first]&&mark[i.second]){
			M-=2;
			mark[i.first]=false;
			mark[i.second]=false;
		}
	}
	bool flag = false;cout<<M<<endl;
	for(int i=0;i<100001;i++){
		if(mark[i]){
			if(!flag) printf("%05d",i),flag=true;
			else printf(" %05d",i);
		}
	}
	return 0;
} 
