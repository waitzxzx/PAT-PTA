#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Record{
	string id_num;
	string in;
	string out;
};
bool cmp1(Record a,Record b){
	return a.in<b.in;
}
bool cmp2(Record a,Record b){
	return a.out<b.out;
}
int main(void){
	int n;
	Record r[1010];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>r[i].id_num>>r[i].in>>r[i].out;
	}
	sort(r,r+n,cmp1);
	cout<<r[0].id_num<<" ";
	sort(r,r+n,cmp2);
	cout<<r[n-1].id_num<<endl;
	return 0;
}
