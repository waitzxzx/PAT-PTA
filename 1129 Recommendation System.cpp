#include<iostream>
#include<map>
#include<algorithm>
#include<set>
using namespace std;
const int MAX = 5e4+7;
struct item{
	int id;int cnt;
	item(int i,int c):id(i),cnt(c){}
	bool operator < (const item &other) const{
		if(cnt!=other.cnt) return cnt>other.cnt;
		else return id<other.id;
	}
};
set<item> s;
int itemCount[MAX]={0};
int main(void){
	int N,K,a;cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>a;
		if(i>0){
			cout<<a<<":";
			int output = 0;
			for(set<item>::iterator i=s.begin();i!=s.end()&&output<K;i++){
				cout<<" "<<(*i).id;
				output++;
			}
			cout<<endl;
		} 
		set<item>::iterator it = s.find(item(a,itemCount[a]));//寻找在set的红黑树中是否已经有这一项 
		itemCount[a]++;
		if(it!=s.end()){//如果有 
			s.erase(it);// 删除后再插入达到修改的目的 
			s.insert(item(a,itemCount[a]));
		}else{//没有找到 
			s.insert(item(a,itemCount[a])); 
		}
	}
	return 0;
}
