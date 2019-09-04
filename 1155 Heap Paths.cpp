#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 1007;
int N;
int levelOrder[MAX];
vector<int> v;
bool isMaxHeap(){
	for(int i=1;i<=N/2;i++){
		if(2*i<=N&&levelOrder[i]<levelOrder[2*i]) return false;
		if(2*i+1<=N&&levelOrder[i]<levelOrder[2*i+1]) return false;
	}
	return true;
}
bool isMinHeap(){
	for(int i=1;i<=N/2;i++){
		if(2*i<=N&&levelOrder[i]>levelOrder[2*i]) return false;
		if(2*i+1<=N&&levelOrder[i]>levelOrder[2*i+1]) return false;
	}
	return true;
}
void output(){
	for(int i=0;i<v.size();i++){
		if(i==0) cout<<v[i];
		else cout<<" "<<v[i];
	}
	cout<<endl;
}
void dfs(int root){
	v.push_back(levelOrder[root]);
	if(2*root>N){
		output();
		v.pop_back(); 
		return;
	}
	if(2*root+1<=N) dfs(2*root+1); 
	if(2*root<=N) dfs(2*root); 
	v.pop_back();
}
int main(void){
	cin>>N;
	for(int i=1;i<=N;i++) cin>>levelOrder[i];
	dfs(1);
	if(isMaxHeap()) puts("Max Heap");
	else if(isMinHeap()) puts("Min Heap");
	else puts("Not Heap");
	return 0;
}
