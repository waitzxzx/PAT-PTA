#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Node{
	int left,right;
};
int toIndex(string s){
	if(s=="-") return -1;
	int ans = 0;
	for(int i=0;i<s.length();i++){
		ans = ans*10+s[i]-'0';
	}
	return ans;
}
int N;Node node[27];
bool visit[27]={false};
bool levelOrder(int root,int& last){
	queue<int> q;
	q.push(root);
	int cnt = 0;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		if(top!=-1){
			cnt++; 
			last = top;
		}
		else{
			return cnt==N;
		}
		q.push(node[top].left);
		q.push(node[top].right);
	}
}
int main(void){
	string l,r;cin>>N;
	for(int i=0;i<N;i++){
		cin>>l>>r;
		if(l!="-"){
			node[i].left = toIndex(l);
			visit[toIndex(l)]=true;
		}
		else node[i].left=-1;
		if(r!="-"){
			node[i].right = toIndex(r);
			visit[toIndex(r)]=true;
		}
		else node[i].right=-1;
	}
	int root = find(visit,visit+N,false)-visit;//—∞’“root
	int last = -1;
	bool flag = levelOrder(root,last);
	if(flag) cout<<"YES "<<last<<endl;
	else cout<<"NO "<<root<<endl;
	return 0;
}
