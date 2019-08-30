#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct Person{
	string id;int age;int worths;
	bool operator < (const Person &other) const{
		if(worths!=other.worths) return worths>other.worths;
		if(age!=other.age) return age<other.age;
		return id<other.id;
	} 
};
const int MAX = 1e5+7;
Person P[MAX];
int main(void){
	int N,K;cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>P[i].id>>P[i].age>>P[i].worths;
	}
	sort(P,P+N);
	int output,Amin,Amax;
	for(int i=1;i<=K;i++){
		cin>>output>>Amin>>Amax;
		cout<<"Case #"<<i<<":"<<endl;
		int cnt = 0;
		for(int i=0;i<N;i++){
			if(cnt>=output) break;
			if(P[i].age>=Amin&&P[i].age<=Amax){
				cout<<P[i].id<<" "<<P[i].age<<" "<<P[i].worths<<endl;
				cnt++;
			}
		}
		if(cnt==0) cout<<"None"<<endl; 
	}
	return 0;
}
