#include<iostream>
#include<vector>
#include<cstring>
#define MIN 0x3f3f3f3f
using namespace std; 
const int MAX = 1e5+7;
int N,M;
int a[MAX]={0};
int sum[MAX]={0};//前i个元素的和 
void init(){
	for(int i=1;i<=N;i++) sum[i]=sum[i-1]+a[i];
}
struct Pair{
	int a;int b;
	Pair(int x,int y):a(x),b(y){};
};
int find(int sum[],int left,int right,int key){//二分查找 
	int mid;
	while(left<right){
		mid = left+(right-left)/2;
		if(sum[mid]>=key) right = mid;
		else left=mid+1;
	}
	return left;
}
vector<Pair> v;
int main(void){
	cin>>N>>M;//数组元素个数、目标金额 
	for(int i=1;i<=N;i++) cin>>a[i];
	init(); v.clear();
	int min = MIN;
	for(int i=0;i<N;i++){
		int j = find(sum,i+1,N,sum[i]+M);
		if(sum[j]-sum[i]>=M&&sum[j]-sum[i]<min){
			min = sum[j]-sum[i];
			v.clear();
			v.push_back(Pair(i+1,j));
		}
		else if(sum[j]-sum[i]>=M&&sum[j]-sum[i]==min){
			v.push_back(Pair(i+1,j));
		}
	}
	for(int i=0;i<v.size();i++) cout<<v[i].a<<"-"<<v[i].b<<endl; 
	return 0; 
}
