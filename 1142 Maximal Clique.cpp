#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
const int N = 207;
int nv,ne;
bool graph[N][N]={false};
set<int> s;
bool isClique(){
	set<int>::iterator i;
	for(i=s.begin();i!=s.end();i++){
		set<int>::iterator j=i;
		for( j++;j!=s.end();j++){
			if(!graph[(*i)][(*j)]) return false;
		}
	}
	return true;
}
bool isMax(){
	for(int i=1;i<=nv;i++){
		if(s.find(i)==s.end()){//如果不在这个集合
			bool flag = false; 
			set<int>::iterator it;
			for(it=s.begin();it!=s.end();it++){
				if(!graph[i][*it]){
					flag =true;break;
				}
			} 
			if(!flag) return false;
		}
	}
	return true;
}
int main(void){
	int a,b,M;cin>>nv>>ne;
	while(ne--){
		cin>>a>>b;
		graph[a][b]=graph[b][a]=true;
	}
	int K,x;cin>>M;
	while(M--){
		s.clear();
		cin>>K;
		while(K--){
			cin>>a;
			s.insert(a); 
		}
		if(!isClique()) cout<<"Not a Clique"<<endl;
		else if(!isMax()) cout<<"Not Maximal"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
