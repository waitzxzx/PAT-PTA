#include<iostream>
using namespace std;
int a[1287][129][61];
bool visit[1287][129][61]={false};
int dir[6][3]={0,0,1,0,0,-1,0,1,0,0,-1,0,1,0,0,-1,0,0};
int M,N,L,T;
int cnt;
void dfs(int i,int j,int k){
	for(int t=0;t<6;t++){
		int ni = i+dir[t][0];
		int nj = j+dir[t][1];
		int nk = k+dir[t][2];
		if(ni>=0&&ni<M&&nj>=0&&nj<N&&nk>=0&&nk<L&&!visit[ni][nj][nk]&&a[ni][nj][nk]){
			visit[ni][nj][nk]=true;
			cnt++;
			dfs(ni,nj,nk);
		}
	}
}
int main(void){
	cin>>M>>N>>L>>T;
	for(int k=0;k<L;k++){
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				cin>>a[i][j][k];
			}
		}
	} 
	int ans = 0;
	for(int k=0;k<L;k++){
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				if(!visit[i][j][k]&&a[i][j][k]){
					visit[i][j][k]=true;
					cnt = 1;
					dfs(i,j,k);
					if(cnt>=T) ans+=cnt;
				}
			}
		}
	} 
	cout<<ans<<endl;
	return 0;
}
