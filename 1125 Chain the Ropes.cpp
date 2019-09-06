#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int N;
priority_queue<int,vector<int> , greater<int> > Q;
int main(void){
	cin>>N;double x;
	for(int i=0;i<N;i++){
		cin>>x;
		Q.push(x);
	}
	while(Q.size()>=2){
		double a = Q.top();
		Q.pop();
		double b = Q.top();
		Q.pop();
		Q.push(0.5*(a+b));
	}
	cout<<(int)(Q.top()+0.5);
	return 0; 
} 
