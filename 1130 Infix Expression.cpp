#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node{
	string data;int left,right;
};
Node node[25];
int root;
bool visit[25]; 
void inOrder(int n){
	if(!(n==root||(node[n].left==-1&&node[n].right==-1))) cout<<"(";
	if(node[n].left!=-1) inOrder(node[n].left);
	cout<<node[n].data;
	if(node[n].right!=-1) inOrder(node[n].right);
	if(!(n==root||(node[n].left==-1&&node[n].right==-1))) cout<<")";
}
int main(void){
	int N;cin>>N;
	string d;int a,b;
	for(int i=1;i<=N;i++){
		cin>>node[i].data>>node[i].left>>node[i].right;
		visit[node[i].left]=true;
		visit[node[i].right]=true;
	}
	root = find(visit+1,visit+N+1,false)-visit;
	inOrder(root);
	return 0;
}
