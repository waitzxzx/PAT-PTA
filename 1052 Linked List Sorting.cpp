#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 1e5+7;
struct Node{
	int address,key,next;
	bool operator < (const Node&other) const{
		return key<other.key;
	}
	Node(){
		address = -1;key = 0;next=-1;
	}
	Node(int a,int k,int n):address(a),key(k),next(n){ }
};
Node node[MAX];
int main(void){
	int N,root;
	cin>>N>>root;
	int address,key,next;
	if(root==-1){
		cout<<0<<" "<<root<<endl;
		return 0;
	}
	for(int i=0;i<N;i++){
		cin>>address>>key>>next;
		node[address] = Node(address,key,next);
	}
	vector<Node> v;
	while(root!=-1){
		v.push_back(node[root]);
		root = node[root].next;
	}
	sort(v.begin(),v.end());
	printf("%d %05d\n",(int)v.size(),v[0].address);
	for(int i=0;i<v.size();i++){
		if(i==v.size()-1)  printf("%05d %d -1\n",v[i].address,v[i].key);
		else printf("%05d %d %05d\n",v[i].address,v[i].key,v[i+1].address);
	}
	return 0;
}
