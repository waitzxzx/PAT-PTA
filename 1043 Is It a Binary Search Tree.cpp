#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
struct Node{
	int data;Node* left;Node* right;
	Node(int d):data(d),left(NULL),right(NULL){ }
};
bool mirror = false;
void insert(Node* &root,int data){//ע�������� 
	if(root == NULL){//���ڵ��ǿգ������½ڵ� 
		root = new Node(data);
		return;
	}
	if(mirror==false){//�Ƕ��������� 
		if(data < root->data) insert(root->left,data);
		else insert(root->right,data); 
	} 
	else{//�Ƕ��������������� 
		if(data >= root->data) insert(root->left,data);
		else insert(root->right,data);
	}
}
void preOrder(Node* root,vector<int>& order){//��������������� 
	order.push_back(root->data);
	if(root->left!=NULL) preOrder(root->left,order);
	if(root->right!=NULL) preOrder(root->right,order);
} 
void postOrder(Node* root,vector<int>& order){//�������ĺ������ 
	if(root->left!=NULL) postOrder(root->left,order);
	if(root->right!=NULL) postOrder(root->right,order);
	order.push_back(root->data); 
} 
int main(void){
	int N,a;cin>>N;
	vector<int> preGot,preGiven,post;
	Node* root = NULL;
	for(int i=0;i<N;i++){
		cin>>a;
		preGiven.push_back(a);
	}
	if(preGiven.size()>1&&preGiven[1]>preGiven[0]) mirror = true;
	for(int i=0;i<N;i++){
		insert(root,preGiven[i]);
	}
	preOrder(root,preGot);
	if(preGot==preGiven){//������ݸ������������ɵĶ�����������ʵ�ʽ���������һ�£���˵������Ϸ� 
		postOrder(root,post);
		cout<<"YES"<<endl;
		for(int i=0;i<post.size();i++){
			if(i==0) cout<<post[i];
			else cout<<" "<<post[i];
		}
	}
	else cout<<"NO"<<endl;
	return 0;
}
