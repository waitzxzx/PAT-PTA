#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<ctype.h>
#include<map>
using namespace std;
struct InsRec{
	string ins;int ns;int tws;int rank;
	InsRec(string i,int n,int t):ins(i),ns(n),tws(t){}
	bool operator < (const InsRec &other) const{
		if(tws!=other.tws) return tws>other.tws;
		if(ns!=other.ns) return ns<other.ns;
		return ins<other.ins;
	}
};
map<string,vector<double> >mp;
vector<InsRec> v;
int main(void){
	int N;cin>>N;
	string id,ins;double grade;
	for(int i=0;i<N;i++){
		cin>>id>>grade>>ins;
		if(id[0]=='B') grade = grade/1.5;
		if(id[0]=='T') grade = grade*1.5;
		transform(ins.begin(),ins.end(),ins.begin(),::tolower);
		mp[ins].push_back(grade);
	}
	map<string,vector<double> >::iterator it;
	for(it = mp.begin();it!=mp.end();it++){
		double sumGrade=0.0;
		for(int i=0;i<(int)(it->second).size();i++){
			sumGrade+=(it->second)[i];
		}
		int cnt = (int)(it->second).size();
		v.push_back(InsRec((it->first),cnt,(int)sumGrade));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		if(i==0||(i>0&&v[i].tws!=v[i-1].tws)) v[i].rank=i+1;
		else v[i].rank = v[i-1].rank;
	}
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i].rank<<" "<<v[i].ins<<" "<<v[i].tws<<" "<<v[i].ns<<endl;
	}
	return 0;
}
