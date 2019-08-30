#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int MAX = 1e3+7;
int Tree[MAX];
int findRoot(int x){
	if(Tree[x]==-1) return x;
	else{
		int temp = findRoot(Tree[x]);
		Tree[x] = temp;
		return temp;
	}
}
struct highway{
	int a,b;
}; 
int main(void){
	int N,M,K;//cities,highways,to be checked
	cin>>N>>M>>K;
	vector<highway> p;
	highway hw;
	for(int i=0;i<M;i++){
		cin>>hw.a>>hw.b;
		p.push_back(hw);
	}
	int t;// what we concern?
	for(int k=0;k<K;k++){
		cin>>t;
		for(int i=1;i<=N;i++) Tree[i]=-1;
		for(int i=0;i<M;i++){
			int c1 = p[i].a;
			int c2 = p[i].b;
			if(c1==t||c2==t) continue;
			c1 = findRoot(c1);
			c2 = findRoot(c2);
			if(c1!=c2){
				Tree[c1]=c2;
			} 
		}
		int branch=0;
		for(int i=1;i<=N;i++){
			if(i==t) continue;
			if(Tree[i]==-1) branch++;
		}
		cout<<branch-1<<endl;
	} 
	return 0;
}
