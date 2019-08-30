#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
struct record{
	int time;string status;
	record(int t,string s):time(t),status(s){}
	bool operator < (const record &other) const{
		return time<other.time;
	}
};
map<string,vector<record> >mp;
vector<record> valid;
int main(void){
	int N,K;cin>>N>>K;
	string p,s;int hh,mm,ss;
	while(N--){
		cin>>p;
		scanf("%d:%d:%d",&hh,&mm,&ss);
		cin>>s;
		mp[p].push_back(record(3600*hh+60*mm+ss,s));
	}
	set<string> maxPlate;
	int maxTime = 0;
	map<string,vector<record> >::iterator i;
	for(i=mp.begin();i!=mp.end();i++){
		sort((i->second).begin(),(i->second.end()));
		int total=0;
		for(int j=0;j<(i->second).size()-1;j++){
			if((i->second)[j].status=="in"&&(i->second)[j+1].status=="out"){
				valid.push_back((i->second)[j]);
				valid.push_back((i->second)[j+1]);
				total+=((i->second)[j+1].time-(i->second)[j].time); 
			}
		}
		if(total>maxTime){
			maxPlate.clear();
			maxPlate.insert(i->first);
			maxTime = total;
		}else if(total==maxTime){
			maxPlate.insert(i->first);
		}
	}
	sort(valid.begin(),valid.end());
	int park = 0;int idx = 0;
	while(K--){
		scanf("%d:%d:%d",&hh,&mm,&ss);
		int t = 3600*hh+60*mm+ss;
		while(idx<valid.size()&&valid[idx].time<=t){
			if(valid[idx].status=="in") park++;
			else park--;
			idx++;
		}
		cout<<park<<endl;
	}
	set<string>::iterator it;
	for(it=maxPlate.begin();it!=maxPlate.end();it++){
		cout<<*it<<" "; 
	} 
	printf("%02d:%02d:%02d",maxTime/3600,maxTime%3600/60,maxTime%60);
	return 0;
} 
