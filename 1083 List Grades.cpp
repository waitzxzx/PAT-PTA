#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct record {
	string name;
	string id;
	int grade;
	bool operator < (const record &other) const{
		return grade>other.grade;
	}
};

int main(void){
	int n,g1,g2;cin>>n;
	record *R=new record[n];
	for(int i=0;i<n;i++) cin>>R[i].name>>R[i].id>>R[i].grade; 
	sort(R,R+n);
	cin>>g1>>g2;
	bool flag = false;
	for(int i=0;i<n;i++){
		if(R[i].grade>=g1&&R[i].grade<=g2){
			flag = true; 
			cout<<R[i].name<<" "<<R[i].id<<endl; 
		}
	}
	if(!flag) cout<<"NONE"<<endl;
	return 0;
}
