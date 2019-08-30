#include<iostream>
#include<queue> 
using namespace std;
bool m[1287][129][61]={false};
int dir[6][3]={0,0,1,0,0,-1,0,1,0,0,-1,0,1,0,0,-1,0,0};
int M,N,L,T;
struct Node{
	int x,y,z;
	Node(int nx,int ny,int nz):x(nx),y(ny),z(nz){}
};
int bfs(Node n){
	queue<Node> q;
	m[n.x][n.y][n.z] = false;
	q.push(n);
	int cnt = 1;
	while(!q.empty()){
		Node p = q.front();
		q.pop();
		for(int i=0;i<6;i++){
			int nx = p.x+dir[i][0];
			int ny = p.y+dir[i][1];
			int nz = p.z+dir[i][2];
			if(nx>=0&&nx<M&&ny>=0&&ny<N&&nz>=0&&nz<L&&m[nx][ny][nz]){
				cnt++;
				m[nx][ny][nz]=false;
				q.push(Node(nx,ny,nz));
			}
		}
	}
	return cnt;
}
int main(void){
	cin>>M>>N>>L>>T;
	int v;
	for(int k=0;k<L;k++){
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				cin>>v;
				if(v==1) m[i][j][k]=true;
			}
		}
	} 
	int ans = 0;
	for(int k=0;k<L;k++){
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				if(m[i][j][k]){
					int cnt = bfs(Node(i,j,k));
					if(cnt>=T) ans+=cnt;
				}
			}
		}
	} 
	cout<<ans<<endl;
	return 0;
}
