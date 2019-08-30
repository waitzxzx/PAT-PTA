#include<iostream>
#include<queue>
using namespace std;
int post[30];
int in[30];
struct Node{
	int data;
	Node* left;
	Node* right; 
	Node(int d):data(d),left(NULL),right(NULL){ }
};  
Node* createTree(int root,int left,int right){
	//����post[]��rootλ�õ�Ԫ�غ�in[]��left��right�����Ԫ�ع����� 
	if(left>right) return NULL;
	Node* r = new Node(post[root]);
	int idx = left;
	while(in[idx]!=post[root]){
		idx++;
	}//idx������������и��ڵ��λ�� 
	r -> left = createTree(root-right+idx-1,left,idx-1);
	r -> right = createTree(root-1,idx+1,right);
	return r;//���뷵�ص�ǰ�ĸ��ڵ� 
}
void levelOrder(Node* root){
	queue<Node*> q;
	q.push(root);
	bool isFirst=true;
	while(!q.empty()){
		Node* front = q.front();
		q.pop();
		if(isFirst){
			cout<<front->data;
			isFirst = false;
		}
		else cout<<" "<<front->data;
		if(front->left!=NULL) q.push(front->left);
		if(front->right!=NULL) q.push(front->right);
	}
}
int main(void){
	int n;cin>>n;
	for(int i=0;i<n;i++) cin>>post[i];
	for(int i=0;i<n;i++) cin>>in[i];
	Node* root = createTree(n-1,0,n-1);
	levelOrder(root);
	return 0;
}
