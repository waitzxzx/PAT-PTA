#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int MAX = 1e5+7;
int nextElem[MAX];
int main(void){
	int start1,start2;char c;int N;
	cin>>start1>>start2>>N;
	int front,rear;
	memset(nextElem,-1,sizeof(nextElem));
	while(N--){
		cin>>front>>c>>rear;
		nextElem[front] = rear;
	}
	vector<int> v1,v2;
	while(start1!=-1){
		v1.push_back(start1);
		start1 = nextElem[start1];
	}
	while(start2!=-1){
		v2.push_back(start2);
		start2 = nextElem[start2];
	}
	int i=v1.size()-1,j=v2.size()-1;
	if(i<0||j<0||v1[i]!=v2[j]){
		printf("-1\n");
	}
	else{
		for(;i>=0&&j>=0&&v1[i]==v2[j];i--,j--);
		printf("%05d\n",v1[i+1]);
	}
	return 0;
}
