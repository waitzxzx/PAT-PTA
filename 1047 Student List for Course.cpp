#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
struct student{
	char name[5];
	bool courses[2501]={false};
	bool operator < (const student &other) const{
		return strcmp(name,other.name)<0;
	}
};
int cnt[2501]={0};
vector<student> s;
int main(void){
	int N,K;cin>>N>>K;
	int size,course;
	for(int i=0;i<N;i++){
		student a;
		scanf("%s%d",&a.name,&size);
		for(int i=0;i<size;i++){
			scanf("%d",&course);
			a.courses[course]=true;
			cnt[course]++;
		} 
		s.push_back(a);
	}
	sort(s.begin(),s.end());
	for(int i=1;i<=K;i++){
		if(cnt[i]!=0){
			cout<<i<<" "<<cnt[i]<<endl;
		}
		for(int j=0;j<N;j++){
			if(s[j].courses[i]==true) printf("%s\n",s[j].name);
		}
	}
	return 0;
}
