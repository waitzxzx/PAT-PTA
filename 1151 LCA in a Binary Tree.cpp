#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int M,N;
const int MAX = 1e4+7;
struct Node{
	int data;int level;int father;//������Ҫ���ݣ�������ĸ��׽����±꣨ǰ�������λ�ã��Ͳ�� 
	Node(int d=0,int l=0,int f=-1):data(d),level(l),father(f){} 
};
Node pre[MAX];//��㾲̬�洢 
int in[MAX];
void createTree(int root,int left,int right,int father,int level){
	//����ǰ�������rootλ�ú����������left��right�������ؽ��� 
	if(left>right) return;
	pre[root] =  Node(pre[root].data,level,father);
	int index = left;
	while(pre[root].data!=in[index]) index++;
	createTree(root+1,left,index-1,root,level+1);
	createTree(root+1+index-left,index+1,right,root,level+1);
}
int main(void){
	cin>>M>>N;
	for(int i=0;i<N;i++) cin>>in[i];
	for(int i=0;i<N;i++) cin>>pre[i].data;
	createTree(0,0,N-1,-1,0);
	int a,b;
	for(int i=0;i<M;i++){
		cin>>a>>b;
		int ai=N;int bi=N;
		for(int i=0;i<N;i++){//�������ݲ�ѯ�����±� 
			if(a==pre[i].data) ai = i;
			if(b==pre[i].data) bi = i;
		}
		if(ai==N&&bi==N) printf("ERROR: %d and %d are not found.\n",a,b);
		else if(ai==N&&bi!=N) printf("ERROR: %d is not found.\n",a);
		else if(ai!=N&&bi==N) printf("ERROR: %d is not found.\n",b);
		else{
			bool deeper = true;//Node a is deeper;
			if(pre[ai].level<pre[bi].level){
				deeper = false;
				swap(ai,bi);
			}
			while(pre[ai].level!=pre[bi].level) ai = pre[ai].father;//ʹ��������������ͬ 
			if(ai==bi){
				printf("%d is an ancestor of %d.\n",(deeper?b:a),(deeper?a:b));//�����ʱ������㵽��ͬһ�� 
			}
			else{
				while(ai!=bi){//����ͬʱ���ϻ��� 
					ai = pre[ai].father;
					bi = pre[bi].father;
				}
				printf("LCA of %d and %d is %d.\n",a,b,pre[ai].data);
			}
		}
	}
	return 0;
}
