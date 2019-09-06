#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
int K,N;bool isOK;
struct Node{
	int data;Node* left;Node* right;
	Node(int d):data(d),left(nullptr),right(nullptr){}
};
void insert(Node* &root,int key){
	if(root==nullptr){
		root = new Node(key);
		return;
	}
	if(abs(key)<abs(root->data)) insert(root->left,key);
	else insert(root->right,key);
}
set<int> s;
void getBlack(Node* root,int cnt){
	if(root==nullptr){
		s.insert(cnt);
		return;
	}
	if(root->data>0) cnt++;
	getBlack(root->left,cnt);
	getBlack(root->right,cnt);
}
void dfs(Node* root){
	if(root==nullptr) return;
	if(root->data<0){
		if(root->left!=nullptr&&root->left->data<0) {isOK = false;return;}
		if(root->right!=nullptr&&root->right->data<0) {isOK = false;return;}
	}
	s.clear();
	getBlack(root,0);
	if(s.size()!=1) {isOK = false;return;}
	if(root->left!=nullptr) dfs(root->left);
	if(root->right!=nullptr) dfs(root->right);
}
int main(void){
	cin>>K;int a;
	while(K--){
		cin>>N;
		Node* root = nullptr;
		isOK = true;
		for(int i=0;i<N;i++){
			cin>>a;
			insert(root,a);
		}
		if(root!=nullptr&&root->data<0) isOK=false;
		if(isOK){
			dfs(root);
		}
		if(isOK) puts("Yes");
		else puts("No");
	}
	return 0;
}
