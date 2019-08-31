#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 1e5+7;
int data[MAX];
int nextAddress[MAX];
bool cmp(int a,int b){
	return data[a]<data[b];
}
int main(void){
	int N,root;
	cin>>N>>root;
	int address,key,nextAdd;
	if(root==-1){
		cout<<"0 -1"<<endl;
		return 0;
	}
	for(int i=0;i<N;i++){
		cin>>address>>key>>nextAdd;
		data[address]=key;
		nextAddress[address]=nextAdd;
	}
	vector<int> v;
	while(root!=-1){
		v.push_back(root);
		root = nextAddress[root];
	}
	sort(v.begin(),v.end(),cmp);
	printf("%d %05d\n",(int)v.size(),v[0]);
	for(int i=0;i<v.size();i++){
		if(i==v.size()-1) printf("%05d %d -1\n",v[i],data[v[i]]);
		else printf("%05d %d %05d\n",v[i],data[v[i]],v[i+1]);
	}
	return 0;
}
