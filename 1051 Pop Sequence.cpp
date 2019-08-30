#include<iostream>
#include<stack>
using namespace std;
int main(void){
	int M,N,K;//capacity,length of push seq
	cin>>M>>N>>K;
	int arr[1007];
	stack<int> st;
	while(K--){
		while(!st.empty()) st.pop();
		bool ans = true;
		int curMax = 0;// 当前已经压栈的最大元素 
		for(int i=1;i<=N;i++) cin>>arr[i];
		//stack 先进后出 
		for(int i=1;i<=N;i++)
		{
			int cur = arr[i];
			if(!st.empty()&&cur==st.top()){//正是当前的栈顶元素 
				st.pop();
			}
			else if(cur>=curMax){//如果已经大于或者等于当前已经压栈的最大元素 
				for(int j=curMax+1;j<=cur;j++){
					st.push(j);
				}
				curMax = cur;
				if(st.size()>M){
					ans = false;
					break;
				}
				st.pop();
			}
			else{//如果小于当前已经压栈的最大元素，不满足FILO，不可能 
				ans = false;
				break;
			}
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	} 
	return 0;
}
