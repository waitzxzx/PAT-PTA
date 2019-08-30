#include<iostream>
#include<vector>
#define MIN 0x3f3f3f3f
using namespace std; 
const int MAX = 1e5+7;
int N,M;
int a[MAX]={0};
struct Pair{
	int a;int b;
	Pair(int x,int y):a(x),b(y){};
};
vector<Pair> v;
int main(void){
	cin>>N>>M;//数组元素个数、目标金额 
	for(int i=1;i<=N;i++) cin>>a[i];
	int sum = a[1];//当前元素i(含)到j的和(含) 
	int min = MIN;
	for(int i=1,j=1;i<=N&&j<=N;){
		if(sum<M){
			j++;
			sum+=a[j];
		}
		else{
			if(sum<min){
				min = sum;
				v.clear();
				v.push_back(Pair(i,j));
			}
			else if(sum==min){
				v.push_back(Pair(i,j));
			}
			sum-=a[i]; 
			i++;
		}
	} 
	for(int i=0;i<v.size();i++) cout<<v[i].a<<"-"<<v[i].b<<endl; 
	return 0; 	
} 
