#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set> 
//1. ����ͬһ�����õ��˷���һ��
//2. ���һ�����ж�����ã������ϲ� 
using namespace std;
const int MAX = 1007;
set<int> cluster[MAX];
vector<int> hobbies[MAX];
void Merge(set<int> &a,set<int> &b){//��b��Ԫ�ز���a 
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
			hobbies[i].push_back(a);//��i���˵İ�����a 
			cluster[a].insert(i);//����a�Ĵؼ����i���� 
			place[a]=a;//����a������һ���أ������±�Ϊa�Ĵ��� 
		}
	}
	for(int i=1;i<=N;i++){
		if(hobbies[i].size()>=2){//����ж�����ã���һ����ͬʱ�������� 
			for(int j=0;j<hobbies[i].size()-1;j++){//����Щͬ���õĴ� 
				int c1 = place[hobbies[i][j]];
				int c2 = place[hobbies[i][j+1]];
				Merge(cluster[c1],cluster[c2]);
				place[c1]=c2;//c1��Ԫ�ض���c2ȥ��
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
