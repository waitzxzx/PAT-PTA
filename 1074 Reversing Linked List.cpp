#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 1e5+7;
int data[MAX];
int nextAdd[MAX];
int main(void){
	int root,N,K;cin>>root>>N>>K;
	int address,key,next;
	for(int i=0;i<N;i++){
		cin>>address>>key>>next;
		data[address]=key;
		nextAdd[address]=next;
	}
	vector<int> v;
	while(root!=-1){
		v.push_back(root);
		root = nextAdd[root];
	}
	for(int i=0;i+K<=v.size();i=i+K){
		reverse(v.begin()+i,v.begin()+i+K);
	}
	for(int i=0;i<v.size();i++){
		if(i==v.size()-1) printf("%05d %d -1\n",v[i],data[v[i]]);
		else printf("%05d %d %05d\n",v[i],data[v[i]],v[i+1]);
	}
	return 0;
} 
