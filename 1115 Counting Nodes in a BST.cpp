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
void Insert(Node* &root,int data){//����ʹ������ 
	if(root==NULL){//�ҵ�����λ�� 
		root = new Node(data);//��̬�����µĽ�� 
		return;
	}//���� 
	if(data<=root->data) Insert(root->left,data);
	else Insert(root->right,data);
}
int maxLevel=0;
void dfs(Node* &root,int level){
	if(root!=NULL){//����ÿһ���ǿս�� 
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
