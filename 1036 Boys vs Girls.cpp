#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int flag;
struct student{
	string name,id;int grade;
	student(string n,string i,int g):name(n),id(i),grade(g){}
	bool operator < (const student &other) const{
		if(flag==1) return grade<other.grade;
		else if(flag==2) return  grade>other.grade;
	}
};
vector<student> boys;
vector<student> girls;
int main(void){
	int n;cin>>n;
	string name,gender,id;int grade;
	while(n--){
		cin>>name>>gender>>id>>grade;
		if(gender=="M") boys.push_back(student(name,id,grade));
		if(gender=="F") girls.push_back(student(name,id,grade));
	}
	flag = 1;sort(boys.begin(),boys.end());
	flag = 2;sort(girls.begin(),girls.end());
	
	if(girls.size()==0) cout<<"Absent"<<endl;
	else  cout<< girls[0].name<<" "<<girls[0].id<<endl;
	
	if(boys.size()==0) cout<<"Absent"<<endl;
	else cout<< boys[0].name<<" "<<boys[0].id<<endl; 
	 
	if(boys.size()==0||girls.size()==0) cout<<"NA"<<endl;
	else cout<<girls[0].grade-boys[0].grade<<endl;
	return 0;
}
