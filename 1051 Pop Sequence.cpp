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
		int curMax = 0;// ��ǰ�Ѿ�ѹջ�����Ԫ�� 
		for(int i=1;i<=N;i++) cin>>arr[i];
		//stack �Ƚ���� 
		for(int i=1;i<=N;i++)
		{
			int cur = arr[i];
			if(!st.empty()&&cur==st.top()){//���ǵ�ǰ��ջ��Ԫ�� 
				st.pop();
			}
			else if(cur>=curMax){//����Ѿ����ڻ��ߵ��ڵ�ǰ�Ѿ�ѹջ�����Ԫ�� 
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
			else{//���С�ڵ�ǰ�Ѿ�ѹջ�����Ԫ�أ�������FILO�������� 
				ans = false;
				break;
			}
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	} 
	return 0;
}
