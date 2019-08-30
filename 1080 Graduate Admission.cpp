#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
struct app{
	int id,ge,gi;int v[5];int rank;
	bool operator < (const app &other) const{
		if(ge+gi!=other.ge+other.gi) return ge+gi>other.ge+other.gi;
		else return ge>other.ge;
	}
};
int quota[107];//���� 
int pass[107]={0};//��¼ȡ���� 
int line[107];//���¼ȡ������ 
vector<int> adm[107];//¼ȡ���� 
vector<app> a;//������ 
int main(void){
	int N,M,K;cin>>N>>M>>K;//N ѧ���� M ������λ K ־Ը�� 
	for(int i=0;i<M;i++) cin>>quota[i];
	app temp;
	for(int i=0;i<N;i++){
		cin>>temp.ge>>temp.gi;
		for(int j=0;j<K;j++) cin>>temp.v[j];
		temp.id = i;
		a.push_back(temp);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<N;i++){//������ֵ 
		if(i==0) a[i].rank = 0;
		else if(a[i].ge==a[i-1].ge&&a[i].gi==a[i-1].gi)  a[i].rank = a[i-1].rank;
		else a[i].rank = i; 
	}
	//for(int i=0;i<N;i++) 	cout<<a[i].ge<<" "<<a[i].gi<<" "<<a[i].rank<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			int curId = a[i].id;
			int curV = a[i].v[j];//־ԸѧУ 
			int curRank = a[i].rank; 
			if(pass[curV]<quota[curV]){//�������� 
				pass[curV]++;
				adm[curV].push_back(curId);
				if(pass[curV]==quota[curV]){//¼ȡ���,�趨���¼ȡ�� 
					line[curV] = curRank; 
				} 
				break;//ÿ����ֻ���ܱ�һ��������λ¼ȡ 
			}
			else{//�Ѿ�û�������� 
				if(curRank==line[curV]){//���Ǵﵽ��������� 
					pass[curV]++;
					adm[curV].push_back(curId);
					break;//ÿ����ֻ���ܱ�һ��������λ¼ȡ 
				} 
			}
		} 
	} 
	for(int i=0;i<M;i++){
		sort(adm[i].begin(),adm[i].end());
		for(int j=0;j<adm[i].size();j++){
			if(j==0) cout<<adm[i][j];
			else cout<<" "<<adm[i][j];
		}
		cout<<endl;
	} 
	return 0;
}
