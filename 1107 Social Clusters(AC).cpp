#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set> 
using namespace std;
const int MAX = 1007;
int cnt[MAX]={0};
int Tree[MAX];
int hobbyCore[MAX];
int findRoot(int x){
	if(Tree[x]==x) return x;
	else{
		int temp = findRoot(Tree[x]);
		Tree[x] = temp;
		return temp;
	}
}
bool cmp(int a,int b){return a>b;}
int main(void){
	int N,k,a;cin>>N;
	for(int i=1;i<=N;i++) Tree[i]=i; 
	memset(hobbyCore,-1,sizeof(hobbyCore));
	for(int i=1;i<=N;i++){
		cin>>k;cin.get();
		while(k--){
			cin>>a;
			if(hobbyCore[a]==-1){//û�д������� 
				hobbyCore[a]=i;//��Ϊ�������� 
			}
			else{
				int na = findRoot(i);//�ҵ�����˵ĸ� 
				int nb = findRoot(hobbyCore[a]);//�ҵ�������ô�������ĸ� 
				if(na!=nb) Tree[na]=nb;//nb��na�ĸ�
			}
		}
	}
	for(int i=1;i<=N;i++){
		cnt[findRoot(i)]++;//cnt[Tree[i]]++�Ǵ���� 
	}
	vector<int> v;
	for(int i=1;i<=N;i++){
		if(cnt[i]!=0){
			v.push_back(cnt[i]);
		}
	}
	cout<<v.size()<<endl;
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		if(i==0) cout<<v[i];
		else cout<<" "<<v[i];
	}
	return 0;
}
