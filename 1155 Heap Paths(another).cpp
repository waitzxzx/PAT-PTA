#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 1007;
int N;
int levelOrder[MAX];
vector<int> v;
bool isMax =true;bool isMin = true; 
void judge(){
	int inc,dec = 0;
	for(int i=0;i<v.size()-1;i++){
		if(isMin&&v[i+1]<v[i]) isMin=false;
		if(isMax&&v[i+1]>v[i]) isMax=false;
	}
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
		judge(); 
		return;
	}
	if(2*root+1<=N){
		dfs(2*root+1);
		v.pop_back();
	} 
	if(2*root<=N){
		dfs(2*root);
		v.pop_back();
	}
}
int main(void){
	cin>>N;
	for(int i=1;i<=N;i++) cin>>levelOrder[i];
	dfs(1);
	if(isMin) puts("Min Heap");
	else if(isMax) puts("Max Heap");
	else puts("Not Heap"); 
	return 0;
}
