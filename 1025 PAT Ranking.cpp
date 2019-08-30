#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct record{
	string id;
	int grade,final_rank,loc_id,loc_rank;
	bool operator < (const record &other) const{
		if(grade!=other.grade) return grade>other.grade;
		else return id<other.id;
	}
}; 
record r[30010];
int main(void)
{
	int N,K;
	int count=1;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>K;
		for(int j=0;j<K;j++){
			cin>>r[count].id>>r[count].grade;
			r[count].loc_id=i;
			count++;
		}
	}
	sort(r+1,r+count);
	for(int i=1;i<=count;i++){
		if(i==1||r[i].grade!=r[i-1].grade) r[i].final_rank=i;
		else r[i].final_rank=r[i-1].final_rank;
	}
	for(int i=1;i<=N;i++){
		int lr = 1;int last_locid=1;
		for(int j=1;j<=count;j++){
			if(r[j].loc_id==i){
				if(lr==1||r[j].grade!=r[last_locid].grade) r[j].loc_rank=lr;
				else r[j].loc_rank=r[last_locid].loc_rank;
				lr++;
				last_locid=j;
			}
		}
	}
	cout<<count-1<<endl;
	for(int i=1;i<=count-1;i++){
		cout<<r[i].id<<" "<<r[i].final_rank<<" "<<r[i].loc_id<<" "<<r[i].loc_rank<<endl;
	}
	return 0;
}
