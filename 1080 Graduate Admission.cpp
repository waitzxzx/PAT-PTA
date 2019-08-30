#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
struct app{
	int id,ge,gi;int v[5];int rank;
	bool operator < (const app &other) const{
		if(ge+gi!=other.ge+other.gi) return ge+gi>other.ge+other.gi;
		else return ge>other.ge;
	}
};
int quota[107];//名额 
int pass[107]={0};//已录取人数 
int line[107];//最低录取排名数 
vector<int> adm[107];//录取名单 
vector<app> a;//申请者 
int main(void){
	int N,M,K;cin>>N>>M>>K;//N 学生数 M 招生单位 K 志愿数 
	for(int i=0;i<M;i++) cin>>quota[i];
	app temp;
	for(int i=0;i<N;i++){
		cin>>temp.ge>>temp.gi;
		for(int j=0;j<K;j++) cin>>temp.v[j];
		temp.id = i;
		a.push_back(temp);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<N;i++){//排名赋值 
		if(i==0) a[i].rank = 0;
		else if(a[i].ge==a[i-1].ge&&a[i].gi==a[i-1].gi)  a[i].rank = a[i-1].rank;
		else a[i].rank = i; 
	}
	//for(int i=0;i<N;i++) 	cout<<a[i].ge<<" "<<a[i].gi<<" "<<a[i].rank<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			int curId = a[i].id;
			int curV = a[i].v[j];//志愿学校 
			int curRank = a[i].rank; 
			if(pass[curV]<quota[curV]){//尚有名额 
				pass[curV]++;
				adm[curV].push_back(curId);
				if(pass[curV]==quota[curV]){//录取完成,设定最低录取线 
					line[curV] = curRank; 
				} 
				break;//每个人只可能被一个招生单位录取 
			}
			else{//已经没有名额了 
				if(curRank==line[curV]){//但是达到最低名次线 
					pass[curV]++;
					adm[curV].push_back(curId);
					break;//每个人只可能被一个招生单位录取 
				} 
			}
		} 
	} 
	for(int i=0;i<M;i++){
		sort(adm[i].begin(),adm[i].end());
		for(int j=0;j<adm[i].size();j++){
			if(j==0) cout<<adm[i][j];
			else cout<<" "<<adm[i][j];
		}
		cout<<endl;
	} 
	return 0;
}
