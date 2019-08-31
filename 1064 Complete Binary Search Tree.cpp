#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int levelOrder[1024],A[1024];
void BST(int left,int right,int index){
	if(left>right) return;
	int depth = (int)floor(log(right-left+2)/log(2));//��ȥ���һ������� 
	int a = (int)pow(2,depth-1);//���������������������������������һ��Ԫ�ظ��� 
	int b = right-left+1-(int)(pow(2,depth)-1); //���һ���Ԫ�ظ��� 
	int num = min(a,b);// ���ڵ�������������һ��Ԫ�ظ���
	int root = left+num+a-1;//ȷ�����ڵ�λ�� 
	levelOrder[index] = A[root];
	BST(left,root-1,2*index);//�ݹ鴦�������� 
	BST(root+1,right,2*index+1);//�ݹ鴦�������� 
}
int main(void){
	int N;cin>>N;
	for(int i=0;i<N;i++) cin>>A[i];
	sort(A,A+N);//���� 
	BST(0,N-1,1);
	for(int i=1;i<=N;i++){
		if(i==1) cout<<levelOrder[i];
		else cout<<" "<<levelOrder[i];
	}
	return 0;
}
