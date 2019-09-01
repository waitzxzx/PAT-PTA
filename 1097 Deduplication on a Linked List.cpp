#include<iostream>
#include<set>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
const int MAX = 1e5+7;
int data[MAX];
int nextAdd[MAX];
int main(void){
	int N,root;cin>>root>>N;
	int address,key,next;
	for(int i=0;i<N;i++){
		cin>>address>>key>>next;
		data[address]=key;
		nextAdd[address]=next;
	}
	set<int> s;
	vector<int> v;
	vector<int> u;
	while(root!=-1){
		if(s.find(abs(data[root]))==s.end()){
			v.push_back(root);
			s.insert(abs(data[root]));
		}
		else{
			u.push_back(root);
		}
		root = nextAdd[root];
	}
	for(int i=0;i<v.size();i++){
		if(i!=v.size()-1)printf("%05d %d %05d\n",v[i],data[v[i]],v[i+1]);
		else printf("%05d %d -1\n",v[i],data[v[i]]);
	}
	for(int i=0;i<u.size();i++){
		if(i!=u.size()-1)printf("%05d %d %05d\n",u[i],data[u[i]],u[i+1]);
		else printf("%05d %d -1\n",u[i],data[u[i]]);
	}
	return 0;
} 
