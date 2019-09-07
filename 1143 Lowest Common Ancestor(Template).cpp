#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int MAX = 1e5+7;
struct Node{
	int data;int father;int level;
	Node(int d=0,int f=-1,int l=0):data(d),father(f),level(l){}
};
int M,N;
Node pre[MAX];
int in[MAX];
void createTree(int root,int left,int right,int father,int level){
	if(left>right) return;
	int index = left;
	while(pre[root].data!=in[index]) index++;
	pre[root] = Node(pre[root].data,father,level);
	createTree(root+1,left,index-1,root,level+1);
	createTree(root+1+index-left,index+1,right,root,level+1);
}
int main(void){
	cin>>M>>N;int a,b;
	for(int i=0;i<N;i++){
		cin>>pre[i].data;
		in[i]=pre[i].data;
	}	
	sort(in,in+N);
	createTree(0,0,N-1,-1,0);
	for(int i=0;i<M;i++){
		cin>>a>>b;
		int ai=N,bi=N;
		for(int i=0;i<N;i++){
			if(pre[i].data==a) ai=i;
			if(pre[i].data==b) bi=i;
		}
		if(ai==N&&bi==N) cout<<"ERROR: "<<a<<" and "<<b<<" are not found."<<endl;
		else if(ai==N&&bi!=N) cout<<"ERROR: "<<a<<" is not found."<<endl;
		else if(ai!=N&&bi==N) cout<<"ERROR: "<<b<<" is not found."<<endl;
		else{
			bool deeper = true;
			if(pre[ai].level<pre[bi].level){
				swap(ai,bi);deeper=false;
			}
			while(pre[ai].level!=pre[bi].level){
				ai = pre[ai].father;
			}
			if(ai==bi) cout<<(deeper?b:a)<<" is an ancestor of "<<(deeper?a:b)<<"."<<endl;
			else{
				while(ai!=bi){
					ai = pre[ai].father;
					bi = pre[bi].father;
				}
				cout<<"LCA of "<<a<<" and "<<b<<" is "<<pre[ai].data<<"."<<endl;
			}
		}
	}
	return 0;
}
