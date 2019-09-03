#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 1e5+7;
int a[MAX];
bool leftPivot[MAX]={false};
bool rightPivot[MAX]={false};
int main(void){
	int N;cin>>N;
	for(int i=0;i<N;i++) cin>>a[i];
	int curMax,curMin;
	for(int i=0;i<N;i++){
		if(i==0){
			curMax = a[i];
			leftPivot[i]=true;
		}
		else if(i>0&&a[i]>curMax){
			leftPivot[i]=true;
			curMax = max(curMax,a[i]);
		}
	}
	for(int i=N-1;i>=0;i--){
		if(i==N-1){
			curMin = a[i];
			rightPivot[i]=true;
		}
		else if(i<N-1&&a[i]<curMin){
			rightPivot[i]=true;
			curMin = min(curMin,a[i]);
		}
	}
	vector<int> v;
	for(int i=0;i<N;i++){
		if(rightPivot[i]&&leftPivot[i]) v.push_back(a[i]);
	}
	cout<<v.size()<<endl;
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		if(i==0) cout<<v[i];
		else cout<<" "<<v[i];
	}
	return 0;
} 
