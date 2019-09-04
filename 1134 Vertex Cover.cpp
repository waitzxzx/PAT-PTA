#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int MAX = 1e4+7;
vector<pair<int,int> >v; 
bool mark[MAX]={false};
int main(void){
	int N,M,K,a,b;cin>>N>>M;
	while(M--){
		cin>>a>>b;
		v.push_back(pair<int,int>(a,b));
	}
	cin>>K;int size,x;
	while(K--){
		cin>>size;
		memset(mark,false,sizeof(mark));
		for(int i=0;i<size;i++){
			cin>>x;
			mark[x]=true;
		}
		bool flag = true;
		for(auto i:v){
			if(!mark[i.first]&&!mark[i.second]) {
				flag = false;
				break;
			}
		}
		if(flag) puts("Yes");
		else puts("No");
	}
	return 0;
}
