#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX = 37;
int post[MAX];int in[MAX];
struct Node{
	int data;Node* left;Node* right;
	int level;
	Node(int d):data(d),left(nullptr),right(nullptr){}
};
int N;
Node* createTree(int root,int left,int right){
	//根据后序遍历的root位置，从中序的left和right区间确定左子树和右子树
	if(left>right) return nullptr;
	Node* cur = new Node(post[root]);
	int idx = left;
	while(post[root]!=in[idx])
		idx++;
	cur->left = createTree(root-right+idx-1,left,idx-1);
	cur->right = createTree(root-1,idx+1,right);
	return cur; 
}
void output(vector<int> &v,int curLevel){
	for(auto i:v){
		if(curLevel==0) cout<<i;
		else cout<<" "<<i;
	}
	v.clear();
}
void levelOrder(Node* &root){
	queue<Node*> q;
	vector<int> v;
	q.push(root);
	int curLevel = 0;
	while(!q.empty()){
		Node* top = q.front();
		q.pop();
		if(top->level>curLevel){
			if(curLevel%2==0) reverse(v.begin(),v.end());
			output(v,curLevel);
			curLevel = top->level;
		}
		v.push_back(top->data);
		if(top->left!=nullptr){
			top->left->level = top->level+1;
			q.push(top->left);
		}
		if(top->right!=nullptr){
			top->right->level = top->level+1;
			q.push(top->right);
		}
	}
	if(!v.empty()){
		if(curLevel%2==0) reverse(v.begin(),v.end());
		output(v,curLevel);
	}
}
int main(void){
	cin>>N;
	for(int i=0;i<N;i++) cin>>in[i];
	for(int i=0;i<N;i++) cin>>post[i];
	Node* root = createTree(N-1,0,N-1);
	root->level =0;
	levelOrder(root);
	return 0;
}
