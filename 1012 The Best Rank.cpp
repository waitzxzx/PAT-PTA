#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
const int MAX = 2007;
int tag=1;
struct Stu{
	string id;
	int c,m,e,a;
	int c_r,m_r,e_r,a_r;
};
bool cmp(Stu a,Stu b){
	if(tag==1) return a.c>b.c;//1 for c;
	else if(tag==2) return a.m>b.m;//2 for m
	else if(tag==3) return a.e>b.e;//3 for e
	else return a.a>b.a;//4 for a
}
int main(void){
	int N,M;
	Stu stu[MAX];
	map<string,int>mp;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>stu[i].id>>stu[i].c>>stu[i].m>>stu[i].e;
		stu[i].a = stu[i].c+stu[i].m+stu[i].e;
	}
	sort(stu,stu+N,cmp);
	for(int i=0;i<N;i++){
		if(i>0 && stu[i].c==stu[i-1].c) stu[i].c_r=stu[i-1].c_r;
		else stu[i].c_r = i+1; 
	}
	tag=2;sort(stu,stu+N,cmp);
	for(int i=0;i<N;i++){
		if(i>0 && stu[i].m==stu[i-1].m) stu[i].m_r=stu[i-1].m_r;
		else stu[i].m_r = i+1; 
	}
	tag=3;sort(stu,stu+N,cmp);
	for(int i=0;i<N;i++){
		if(i>0 && stu[i].e==stu[i-1].e) stu[i].e_r=stu[i-1].e_r;
		else stu[i].e_r = i+1; 
	}
	tag=4;sort(stu,stu+N,cmp);
	for(int i=0;i<N;i++){
		if(i>0 && stu[i].a==stu[i-1].a) stu[i].a_r=stu[i-1].a_r;
		else stu[i].a_r = i+1; 
	}
	for(int i=0;i<N;i++) mp[stu[i].id]=i+1;//将id和当前对象数组的下标映射起来
	string str;
	for(int i=0;i<M;i++){
		cin>>str;
		if(mp[str]){
			int idx = mp[str]-1;
			int bestRank = stu[idx].a_r;
			char bestSub = 'A';
			if(stu[idx].c_r<bestRank) bestRank=stu[idx].c_r,bestSub='C';
			if(stu[idx].m_r<bestRank) bestRank=stu[idx].m_r,bestSub='M';
			if(stu[idx].e_r<bestRank) bestRank=stu[idx].e_r,bestSub='E';
			cout<<bestRank<<" "<<bestSub<<endl;
		}else{
			cout<<"N/A"<<endl;
		}
	} 
	return 0;
}
