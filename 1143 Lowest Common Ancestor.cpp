#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#define LEN 10007
using namespace std;
struct Node{
	int data;Node* left;Node* right;
	Node(int d):data(d),left(NULL),right(NULL){}
};
map<int,int> mp;//key-index
int arr[LEN];//index-key
int pre[LEN]; 
void insertNode(Node* &root ,Node* father, int data){
	if(root==NULL){
		root = new Node(data);
		if(father==NULL) pre[mp[data]]=-1;
		else pre[mp[data]]=mp[father->data];
		return;
	}
	if(data<root->data) insertNode(root->left,root,data);
	else insertNode(root->right,root,data);
}
vector<int> v1,v2; 
void backTracking(int leaf,vector<int> &v){
	v.push_back(leaf);
	if(pre[leaf]==-1) return;
	backTracking(pre[leaf],v);
}
int main(void){
	int M,N,a,b;cin>>M>>N;
	Node* root = NULL;
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
		mp[arr[i]]=i;
		insertNode(root,NULL,arr[i]);
	}
	while(M--){
		cin>>a>>b;
		if(mp.find(a)==mp.end()&&mp.find(b)!=mp.end()) cout<<"ERROR: "<<a<<" is not found."<<endl;
		else if(mp.find(a)!=mp.end()&&mp.find(b)==mp.end()) cout<<"ERROR: "<<b<<" is not found."<<endl;
		else if((mp.find(a)==mp.end()&&mp.find(b)==mp.end())) cout<<"ERROR: "<<a<<" and "<<b<<" are not found."<<endl;
		else{
			v1.clear();v2.clear();
			backTracking(mp[a],v1);backTracking(mp[b],v2);
			reverse(v1.begin(),v1.end());
			reverse(v2.begin(),v2.end());
			for(int i=0;i<v1.size()&&i<v2.size();i++){
				if(v1[i]!=v2[i]){
					cout<<"LCA of "<<a<<" and "<<b<<" is "<<arr[v1[i-1]]<<"."<<endl;
					break;
				}
				if(i==v1.size()-1) cout<<a<<" is an ancestor of "<<b<<"."<<endl;
				else if(i==v2.size()-1) cout<<b<<" is an ancestor of "<<a<<"."<<endl;
			} 
		}
	}
	return 0;
}
