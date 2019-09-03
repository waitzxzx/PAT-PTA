#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 1e4+7;
int n[MAX];
bool cmp(int a,int b){return a>b;}
int main(void){
	int N;cin>>N;
	for(int i=0;i<N;i++) cin>>n[i];
	sort(n,n+N,cmp);//���� 
	int col = sqrt(N);//ȷ��������εĸߺͿ� 
	do{
		if(N%col==0) break;
	}while(col--);
	int row = N/col;
	int a[row][col];
	memset(a,0,sizeof(a));
	int i=0,j=-1;//��ʼλ�� 
	int dirIndex = 0;
	int dir[4][2]={0,1, 1,0, 0,-1, -1,0};
	for(int k=0;k<N;k++){
		int ii = i+dir[dirIndex%4][0];
		int jj = j+dir[dirIndex%4][1];
		if(ii<0||ii>=row||jj<0||jj>=col||a[ii][jj]!=0){
		//�������ά�ֵ�ǰ������������Χ 
			dirIndex++;//������� 
		} 
		i = i+dir[dirIndex%4][0];
		j = j+dir[dirIndex%4][1];
		a[i][j]=n[k];
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(j==0) cout<<a[i][j];
			else cout<<" "<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
