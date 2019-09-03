#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set> 
//1. 把有同一个爱好的人放在一起
//2. 如果一个人有多个爱好，两两合并 
using namespace std;
const int MAX = 1007;
set<int> cluster[MAX];
vector<int> hobbies[MAX];
void Merge(set<int> &a,set<int> &b){//把b的元素插入a 
	set<int>::iterator it; 
	for(it = a.begin();it!=a.end();it++){
		b.insert(*it);
	}
	a.clear();
}
int place[MAX];
bool cmp(int a,int b){return a>b;}
int main(void){
	int N,K,a;cin>>N;
	for(int i=1;i<=N;i++){
		cin>>K;cin.get();
		while(K--){
			cin>>a;
			hobbies[i].push_back(a);//第i个人的爱好有a 
			cluster[a].insert(i);//爱好a的簇加入第i个人 
			place[a]=a;//爱好a的人是一个簇，放在下标为a的簇中 
		}
	}
	for(int i=1;i<=N;i++){
		if(hobbies[i].size()>=2){//如果有多个爱好，即一个人同时在两个簇 
			for(int j=0;j<hobbies[i].size()-1;j++){//将这些同爱好的簇 
				int c1 = place[hobbies[i][j]];
				int c2 = place[hobbies[i][j+1]];
				Merge(cluster[c1],cluster[c2]);
				place[c1]=c2;//c1的元素都在c2去了
			}
		}
	}
	vector<int> v;
	for(int i=1;i<=1000;i++){
		if(!cluster[i].empty()){
			v.push_back(cluster[i].size());
		}
	}
	sort(v.begin(),v.end(),cmp);
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++){
		if(i==0) cout<<v[i];
		else cout<<" "<<v[i];
	}
	return 0;
}
