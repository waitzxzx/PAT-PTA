#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<unordered_map>
using namespace std;
const int MAX = 1e4+7;
int N,M;
struct card{
	string cardNumber;
	string level;int site,date,number;int score;
};
bool cmp(card a,card b){
	if(a.score!=b.score) return a.score>b.score;
	return a.cardNumber<b.cardNumber; 
}
bool cmp2(pair<int,int> p1,pair<int,int> p2) {
    if(p1.second!=p2.second) return p1.second>p2.second;
    else return p1.first<p2.first;
}
card c[MAX];
int main(void){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>c[i].cardNumber>>c[i].score;
		c[i].level = c[i].cardNumber.substr(0,1);
		c[i].site = stoi(c[i].cardNumber.substr(1,3));
		c[i].date = stoi(c[i].cardNumber.substr(4,6));
		c[i].number = stoi(c[i].cardNumber.substr(10,3));
	}
	int type;string s;
	sort(c,c+N,cmp); 
	for(int i=1;i<=M;i++){
		cin>>type>>s;
		cout<<"Case "<<i<<": "<<type<<" "<<s<<endl; 
		if(1==type){
			bool flag = false; 
			for(int i=0;i<N;i++){
				if(s==c[i].level){
					printf("%s %d\n",c[i].cardNumber.c_str(),c[i].score);
					flag = true;
				} 
			}
			if(!flag) puts("NA");
		}
		else if(2==type){
			int nt=0,ns=0;int key = stoi(s);
			for(int i=0;i<N;i++){
				if(c[i].site==key){
					nt++;
					ns+=c[i].score; 
				}
			}
			if(nt>0) cout<<nt<<" "<<ns<<endl;
			else puts("NA");
		}
		else if(3==type){
			unordered_map<int,int> mp;int key = stoi(s);
			for(int i=0;i<N;i++){
				if(key== c[i].date){
					mp[c[i].site]++;
				}
			} 
			if(mp.size()==0) puts("NA");
			else{
				vector<pair<int,int> >vec(mp.begin(),mp.end());
				sort(vec.begin(),vec.end(),cmp2);
				for(int i=0;i<vec.size();i++){
					printf("%03d %d\n",vec[i].first,vec[i].second);
				}
			}
		} 
	}
	return 0;
}
