#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node{
	int data;Node* left;Node* right;
	Node(int d):data(d),left(NULL),right(NULL){	}
};
int levelCnt[1007]={0};
void Insert(Node* &root,int data){//必须使用引用 
	if(root==NULL){//找到插入位置 
		root = new Node(data);//动态建立新的结点 
		return;
	}//否则 
	if(data<=root->data) Insert(root->left,data);
	else Insert(root->right,data);
}
int maxLevel=0;
void dfs(Node* &root,int level){
	if(root!=NULL){//对于每一个非空结点 
		levelCnt[level]++;
		maxLevel = max(maxLevel,level);
	}
	if(root->left!=NULL){
		dfs(root->left,level+1);
	}
	if(root->right!=NULL){
		dfs(root->right,level+1);
	}
}
int main(void){
	int N,a;cin>>N;
	Node* root = NULL;
	for(int i=0;i<N;i++){
		cin>>a;
		Insert(root,a);
	}
	dfs(root,0);
	cout<<levelCnt[maxLevel]<<" + "<<levelCnt[maxLevel-1]<<" = "<<levelCnt[maxLevel]+levelCnt[maxLevel-1]<<endl;
	return 0;
}
