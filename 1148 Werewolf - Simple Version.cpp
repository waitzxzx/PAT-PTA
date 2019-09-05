#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
using namespace std;
const int MAX = 107;
int N;
int a[MAX];
bool W[MAX]={false};
bool judge(int x,int y){
	memset(W,false,sizeof(W));
	W[x]=true;W[y]=true;
	int humanCnt=0;int wolfCnt = 0;//说的真话 
	for(int i=1;i<=N;i++){
		if(!W[i]){//如果是平民 
			if((a[i]>0&&!W[a[i]])||(a[i]<0&&W[-a[i]])) humanCnt++;
		} 
		else{//如果是狼人 
			if((a[i]>0&&!W[a[i]])||(a[i]<0&&W[-a[i]])) wolfCnt++; 
		}
	}
	if(humanCnt==N-3&&wolfCnt==1) return true;
	else return false; 
}
int main(void){
	cin>>N;
	for(int i=1;i<=N;i++) cin>>a[i];
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			if(judge(i,j)){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	cout<<"No Solution";
	return 0;
}
