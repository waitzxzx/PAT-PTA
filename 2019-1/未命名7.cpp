#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<vector>
#include<map>
#include<queue>
#include<set> 
#include<cmath>
using namespace std;
int N,M;
struct Node{
	int data;Node* left;Node* right;int level;
	Node(int d):data(d),left(nullptr),right(nullptr),level(0){}
}; 
int post[55];int in[55];
Node* createTree(int root,int left,int right){
	if(left>right) return nullptr;
	Node* p = new Node(post[root]);
	int index = left;
	while(post[root]!=in[index]) index++;
	p->left  = createTree(root-right+index-1,left,index-1);
	p->right = createTree(root-1,index+1,right);
	return p;
}
bool isOK;
void levelDFS(Node* root){
	if(root==nullptr) return;
	if(root->left!=nullptr){
		root->left->level = root->level+1;
		levelDFS(root->left);
	} 
	if(root->right!=nullptr){
		root->right->level = root->level+1;
		levelDFS(root->right);
	}
} 
int cmd;int x,y;int xl,yl;
void checkDFS(Node* root){
	if(root==nullptr) return;
	if(cmd==2&&root->left!=nullptr&&root->right!=nullptr&&((root->left->data==x&&root->right->data==y)||(root->left->data==y&&root->right->data==x))){
		isOK = true;return;
	}else if(cmd==3&&root->data==x&&((root->left!=nullptr&&root->left->data==y)||(root->right!=nullptr&&root->right->data==y))){
		isOK = true;return;
	}else if(cmd==4&&root->left!=nullptr&&root->left->data==x&&root->data==y){
		isOK = true;return;
	}else if(cmd==5&&root->right!=nullptr&&root->right->data==x&&root->data==y){
		isOK = true;return;
	}else if(cmd==6&&root->data==x){
		xl = root->level;
	}else if(cmd==6&&root->data==y){
		yl = root->level;
	}else if(cmd==7&&((root->left==nullptr&&root->right!=nullptr)||(root->left!=nullptr&&root->right==nullptr))){
		isOK = false;return;
	}
	checkDFS(root->left);
	checkDFS(root->right);
}
int main(void){
	cin>>N;
	for(int i=0;i<N;i++) cin>>post[i];
	for(int i=0;i<N;i++) cin>>in[i];
	Node* root = nullptr;
	root = createTree(N-1,0,N-1);
	levelDFS(root);
	cin>>M;string s;getchar();
	while(M--){
		getline(cin,s);
		if(s.find("root")!=s.npos){
			isOK = false;
			sscanf(s.c_str(),"%d is the root",&x);
			if(root->data==x) isOK = true;
		}
		else if(s.find("siblings")!=s.npos){
			sscanf(s.c_str(),"%d and %d are siblings",&x,&y); 
			isOK =false;cmd=2;checkDFS(root);
		}
		else if(s.find("parent")!=s.npos){
			sscanf(s.c_str(),"%d is the parent of %d",&x,&y); 
			isOK=false;cmd=3;checkDFS(root);
		}
		else if(s.find("left")!=s.npos){
			sscanf(s.c_str(),"%d is the left child of %d",&x,&y); 
			isOK=false;cmd=4;checkDFS(root);
		}
		else if(s.find("right")!=s.npos){
			sscanf(s.c_str(),"%d is the right child of %d",&x,&y); 
			isOK=false;cmd=5;checkDFS(root);
		}
		else if(s.find("level")!=s.npos){
			sscanf(s.c_str(),"%d and %d are on the same level",&x,&y); 
			isOK=false;cmd=6;checkDFS(root);
			if(xl==yl) isOK=true; 
		}
		else if(s.find("full")!=s.npos){
			isOK = true;cmd=7;checkDFS(root);
		}
		if(isOK) puts("Yes");
		else puts("No"); 
	}
	return 0;
}
