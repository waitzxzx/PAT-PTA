#include<iostream>
#include<vector> 
#include<cstring>
using namespace std;
const int MAX = 5e4+7;
struct Node{
	int data;Node* left;Node* right;
	Node(int d):data(d),left(nullptr),right(nullptr){}
};
int pre[MAX],in[MAX];
Node* createTree(int root,int left,int right){
	//前序遍历的root位置是根节点，根据中序的left到right区分左右子树
	if(left>right) return nullptr;
	Node* p = new Node(pre[root]);
	int index = left;
	while(in[index]!=pre[root]) index++;
	p->left = createTree(root+1,left,index-1);
	p->right = createTree(root+index-left+1,index+1,right);
	return p;
}
vector<int> v;
void postOrder(Node* root){
	if(root->left!=nullptr) postOrder(root->left);
	if(root->right!=nullptr) postOrder(root->right);
	v.push_back(root->data);
}
int N;
int main(void){
	cin>>N;
	for(int i=0;i<N;i++) cin>>pre[i];
	for(int i=0;i<N;i++) cin>>in[i];
	Node *root = nullptr;
	root = createTree(0,0,N-1);
	postOrder(root);
	cout<<v[0]<<endl;
	return 0;
}
