//关于string比较等
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct record{
	int id;
	string name;
	int grade;
};
bool cmp1(record a,record b){
	return a.id<b.id;
}
bool cmp2(record a,record b){
	if(a.name!=b.name) return a.name<b.name;
	return a.id<b.id;
}
bool cmp3(record a,record b){
	if(a.grade!=b.grade) return a.grade<b.grade;
	return a.id<b.id;
}
record R[10001];
int main(void){
	int n,c;
	cin>>n>>c;
	for(int i=0;i<n;i++){
		//scanf("%s%s%d",&R[i].id,&R[i].name,&R[i].grade);
		cin>>R[i].id>>R[i].name>>R[i].grade; 
	}
	if(c==1) sort(R,R+n,cmp1);
	else if(c==2) sort(R,R+n,cmp2);
	else sort(R,R+n,cmp3); 
	for(int i=0;i<n;i++){
		printf("%06d %s %d\n",R[i].id,R[i].name.c_str(),R[i].grade);
	}
	return 0;
}
