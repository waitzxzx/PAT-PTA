#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,K,M;//users pros submissions
struct user{
	int id;int rank;
	bool isSolved[6]={false};
	bool isCompiled[6]={false};
	bool hasSubmitted[6]={false};
	bool isShown=false;
	int marks[6];
	int solvedCnt=0;
	int totalScore=0;
	void shown(){
		for(int i=1;i<=K;i++){
			if(isCompiled[i]){
				isShown=true;break;
			}
		}
	}
	void scoreSum(){
		for(int i=1;i<=K;i++) totalScore+=marks[i];
	}
	void solvedSum(){
		for(int i=1;i<=K;i++){
			if(isSolved[i]) solvedCnt++;
		}
	}
	bool operator < (const user &other) const{
		if(totalScore!=other.totalScore) return totalScore>other.totalScore;
		if(solvedCnt!=other.solvedCnt) return solvedCnt>other.solvedCnt;
		return id<other.id;
	}
};
const int MAX = 1e4+7;
int full[6];
user U[MAX];
int main(void){
	cin>>N>>K>>M;
	for(int i=1;i<=N;i++){
		U[i].id = i;
	}
	for(int i=1;i<=K;i++) cin>>full[i];
	int id,proid,score;
	while(M--){
		cin>>id>>proid>>score;
		U[id].hasSubmitted[proid]=true;
		if(score>=0){
			U[id].isCompiled[proid] = true;
			if(score>U[id].marks[proid]){
				U[id].marks[proid]=score;
				if(score==full[proid]){
					 U[id].isSolved[proid] = true;
				}
			}
		}
	}
	for(int i=1;i<=N;i++){
		U[i].scoreSum();
		U[i].solvedSum();
		U[i].shown();
	}
	sort(U+1,U+N+1);
	for(int i=1;i<=N;i++){
		if(i==1||U[i].totalScore!=U[i-1].totalScore){
			U[i].rank=i;
		} else if(U[i].totalScore==U[i-1].totalScore){
			U[i].rank=U[i-1].rank;
		}
	}
	for(int i=1;i<=N;i++){
		if(U[i].isShown){
			printf("%d %05d %d",U[i].rank,U[i].id,U[i].totalScore);
			for(int j=1;j<=K;j++){
				if(U[i].hasSubmitted[j]==false ) cout<<" -";
				else cout<<" "<<U[i].marks[j];
			}
			cout<<endl;
		}
	}
	return 0;
}
