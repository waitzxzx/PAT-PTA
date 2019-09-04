#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 1e5+7;
struct Node{
	int address,key,nextAdd;
};
Node node[MAX];
int start,N,K;
int main(void){
	cin>>start>>N>>K;
	int a,k,n;
	while(N--){
		cin>>a>>k>>n;
		node[a].address=a;
		node[a].key=k;
		node[a].nextAdd=n;
	}
	vector<Node> v;
	while(start!=-1){
		v.push_back(node[start]);
		start = node[start].nextAdd;
	}
	vector<Node> ans;
	for(int i=0;i<v.size();i++){
		if(v[i].key<0) ans.push_back(v[i]);
	}
	for(int i=0;i<v.size();i++){
		if(v[i].key>=0&&v[i].key<=K) ans.push_back(v[i]);
	}
	for(int i=0;i<v.size();i++){
		if(v[i].key>K) ans.push_back(v[i]);
	}
	for(int i=0;i<ans.size()-1;i++) printf("%05d %d %05d\n",ans[i].address,ans[i].key,ans[i+1].address);
	printf("%05d %d -1\n",ans.back().address,ans.back().key);
	return 0;
}
