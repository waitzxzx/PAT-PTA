#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node{
	int left=-1;int right=-1;
};
Node node[17];
bool visit[17]={false};
int string2int(string s){
	int ans = 0;
	for(int i=0;i<s.length();i++){
		ans = ans*10+s[i]-'0';
	}
	return ans;
}
void levelOrder(int root,vector<int> &v){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int top = q.front();
		q.pop();
		v.push_back(top);
		if(node[top].left!=-1) q.push(node[top].left);
		if(node[top].right!=-1) q.push(node[top].right);
	}
} 
void output(vector<int> &v){
	for(int i=0;i<v.size();i++){
		if(i==0) cout<<v[i];
		else cout<<" "<<v[i];
	}
	cout<<endl;
	v.clear();
}
void inOrder(int root,vector<int> &s){
	if(node[root].left!=-1) inOrder(node[root].left,s);
	s.push_back(root);
	if(node[root].right!=-1) inOrder(node[root].right,s);
} 
int main(void){
	int N;cin>>N;
	string a,b;
	for(int i=0;i<N;i++){
		cin>>a>>b;
		if(a!="-"){//·´×Å´æ´¢ 
			node[i].right = string2int(a);
			visit[node[i].right] = true;
		}
		if(b!="-"){
			node[i].left = string2int(b);
			visit[node[i].left] = true;
		}
	}
	int root = find(visit,visit+N,false)-visit;
	vector<int> s;
	levelOrder(root,s);
	output(s);
	inOrder(root,s);
	output(s);
	return 0;
}
