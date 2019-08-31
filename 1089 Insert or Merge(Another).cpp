#include<iostream>
#include<cstring>
#include<algorithm>
#include<memory.h>
using namespace std;
int a[101];
int b[101];
int target[101];
int N;
bool isEqual(int arr[]){
	for(int i=0;i<N;i++){
		if(arr[i]!=target[i]) return false;
	}
	return true;
}
void output(int arr[]){
	for(int i=0;i<N;i++){
		if(i==0) cout<<arr[i];
		else cout<<" "<<arr[i];
	} 
}
int main(void){
	cin>>N;
	for(int i=0;i<N;i++) cin>>a[i];
	for(int i=0;i<N;i++) cin>>target[i];
	memcpy(b,a,sizeof(a));
	bool isInsert = false;
	for(int i=2;i<=N;i++){
		sort(a,a+i);
		if(isEqual(a)){
			cout<<"Insertion Sort"<<endl;
			sort(a,a+i+1);
			output(a); 
			isInsert = true;
			break;
		}
	}
	if(!isInsert){
		bool flag = false;
		for(int i=2;i<=N;i=i*2){
			for(int j=0;j<N;j+=i){
				sort(b+j,j+i>=N?b+N:b+j+i);
			}
			if(flag){
				cout<<"Merge Sort"<<endl;
				output(b);
				break;
			} 
			if(isEqual(b)){
				flag = true;
			}
		}
	}
	return 0;
}
