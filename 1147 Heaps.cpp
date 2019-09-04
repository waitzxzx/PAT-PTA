#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int M,N;
int levelOrder[1007];
bool isMaxHeap(){
	for(int i=1;i<=N/2;i++){
		if(2*i<=N){
			if(!(levelOrder[i]>=levelOrder[2*i])) return false;
		}
		if(2*i+1<=N){
			if(!(levelOrder[i]>=levelOrder[2*i+1])) return false;
		}
	}
	return true;
}
bool isMinHeap(){
	for(int i=1;i<=N/2;i++){
		if(2*i<=N){
			if(!(levelOrder[i]<levelOrder[2*i])) return false;
		}
		if(2*i+1<=N){
			if(!(levelOrder[i]<levelOrder[2*i+1])) return false;
		}
	}
	return true;
}
vector<int> v;
void postOrder(int root){
	if(2*root<=N) postOrder(2*root);
	if(2*root+1<=N) postOrder(2*root+1);
	v.push_back(levelOrder[root]);
}
int main(void){
	cin>>M>>N;
	while(M--){
		for(int i=1;i<=N;i++) cin>>levelOrder[i];
		if(isMaxHeap()) puts("Max Heap");
		else if(isMinHeap()) puts("Min Heap");
		else puts("Not Heap");
		v.clear();
		postOrder(1);
		for(int i=0;i<v.size();i++){
			if(i==0) cout<<v[i];
			else cout<<" "<<v[i];
		}
		cout<<endl;
	}
	return 0;
}
