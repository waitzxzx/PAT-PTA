#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int levelOrder[1024],A[1024];
void BST(int left,int right,int index){
	if(left>right) return;
	int depth = (int)floor(log(right-left+2)/log(2));//除去最后一层的树深 
	int a = (int)pow(2,depth-1);//如果将该树补足成满二叉树的左子树最后一层元素个数 
	int b = right-left+1-(int)(pow(2,depth)-1); //最后一层的元素个数 
	int num = min(a,b);// 根节点的左子树的最后一层元素个数
	int root = left+num+a-1;//确定根节点位置 
	levelOrder[index] = A[root];
	BST(left,root-1,2*index);//递归处理左子树 
	BST(root+1,right,2*index+1);//递归处理右子树 
}
int main(void){
	int N;cin>>N;
	for(int i=0;i<N;i++) cin>>A[i];
	sort(A,A+N);//排序 
	BST(0,N-1,1);
	for(int i=1;i<=N;i++){
		if(i==1) cout<<levelOrder[i];
		else cout<<" "<<levelOrder[i];
	}
	return 0;
}
