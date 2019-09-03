#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct person{
	string name;int height;
	bool operator < (const person &other)const{
		if(height!=other.height) return height>other.height;
		return name<other.name;
	}
	person(string n,int h):name(n),height(h){}
};
vector<person> people;
vector<person> row;
vector<person> v;
void sortRow(vector<person> &v){
	row.clear();
	for(int i=0;i<v.size();i++){
		if(i==0) row.push_back(v[i]);
		else{
			if(i%2==1) row.insert(row.begin(),v[i]);
			else row.push_back(v[i]);
		}
	}
	for(int i=0;i<row.size();i++){
		if(i==0) cout<<row[i].name;
		else cout<<" "<<row[i].name;
	}
	cout<<endl;
	v.clear();
}
int main(void){
	int N,K,h;string s;cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>s>>h;
		people.push_back(person(s,h));
	}
	sort(people.begin(),people.end());
	int last = N - (N/K)*(K-1) ;
	v.clear();
	for(int i=0;i<people.size();i++){
		v.push_back(people[i]);
		if(i+1>=last&&(i+1-last)%(N/K)==0){
			sortRow(v);
		} 
	} 
	return 0;
	
}
