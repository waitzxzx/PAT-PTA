#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
struct Node{
	int data;int left,right;
	Node(){	data = 0;left=right=-1;	}
};
Node node[107];
int a[107];
int idx = 0;
void insert(int root){//中序遍历，同时完成赋值 
	if(node[root].left!=-1){
		insert(node[root].left);
	}
	node[root].data = a[idx];idx++;
	if(node[root].right!=-1){
		insert(node[root].right);
	} 
}
vector<Node> levelOrder(){//利用队列完成层次遍历 
	queue<Node> q;
	vector<Node> ans;
	q.push(node[0]);
	while(!q.empty()){
		Node cur = q.front();
		ans.push_back(cur);
		q.pop();
		if(cur.left!=-1) q.push(node[cur.left]);
		if(cur.right!=-1) q.push(node[cur.right]);
	}
	return ans;
}
int main(void){
	int N;cin>>N;
	for(int i=0;i<N;i++){
		cin>>node[i].left>>node[i].right;
	}
	for(int i=0;i<N;i++) cin>>a[i];
	sort(a,a+N); 
	insert(0);
	vector<Node> order = levelOrder();
	for(int i=0;i<order.size();i++){
		if(i==0) cout<<order[i].data;
		else cout<<" "<<order[i].data;
	}
	return 0;
}
