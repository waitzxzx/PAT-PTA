#include<bits/stdc++.h>
using namespace std;
int N,pre[30],post[30];
vector<int>in;
bool flag = true;
void inOrder(int root,int left,int right){
	if(left>=right){
		if(left==right)
			in.push_back(pre[root]);
		return;
	}
	int index = left;
	while(post[index]!=pre[root+1]){
		index++;
	}
	if(index==right-1) flag=false;
	inOrder(root+1,left,index);
	in.push_back(pre[root]);
	inOrder(root+2+index-left,index+1,right-1);
} 
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;++i)
        scanf("%d",&pre[i]);
    for(int i=0;i<N;++i)
        scanf("%d",&post[i]);
    inOrder(0,0,N-1);
    printf("%s\n",flag==true?"Yes":"No");
    for(int i=0;i<in.size();++i)
        printf("%s%d",i>0?" ":"",in[i]);
    printf("\n");
    return 0;
}
