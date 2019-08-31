#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct record{
	int id;int T,V;//²Å¡¢µÂ 
	record(int i,int t,int v):id(i),T(t),V(v){}
	bool operator < (const record &other) const{
		if(T+V!=other.T+other.V) return T+V>other.T+other.V;
		if(V!=other.V) return V>other.V;
		return id<other.id;
	}
};
vector<record>sages,nobelman,foolman,smallman; 
void output(vector<record> &v){
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		printf("%08d %02d %02d\n",v[i].id,v[i].V,v[i].T);
	}
}
int main(void){
	int N,L,H;cin>>N>>L>>H;
	int id,T,V;
	for(int i=0;i<N;i++){
		cin>>id>>V>>T;
		if(T>=L&&V>=L){
			if(T>=H&&V>=H) sages.push_back(record(id,T,V));
			else if(T<H&&V>=H) nobelman.push_back(record(id,T,V));
			else if(T<H&&V<H&&V>=T) foolman.push_back(record(id,T,V));
			else smallman.push_back(record(id,T,V)); 
		}
	}
	cout<<sages.size()+nobelman.size()+foolman.size()+smallman.size()<<endl;
	output(sages);output(nobelman);output(foolman);output(smallman);
	return 0;
} 
