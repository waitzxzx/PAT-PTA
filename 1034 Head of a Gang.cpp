#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 2007;
int Tree[MAX];
int w[MAX];//每个成员的权重 
int total[MAX];//帮派的权重 
int num[MAX];//帮派人数 
int findRoot(int x){
	if(Tree[x]==-1) return x;
	else{
		int temp = findRoot(Tree[x]);
		Tree[x] = temp;
		return temp;
	}
} 
struct Gang{
	string headName;int n;
	Gang(string h,int num):headName(h),n(num){}
	bool operator < (const Gang &other) const{
		return headName<other.headName;
	}
};
string name[MAX];
map<string,int> mp;//用于编号和姓名之间相互转换 
int main(void){
	int N,K;cin>>N>>K;
	for(int i=1;i<=MAX;i++){//memset不可以赋值1 ！！！ 
		num[i]=1;
	}
	memset(Tree,-1,sizeof(Tree));
	memset(w,0,sizeof(w));
	memset(total,0,sizeof(total)); 
	string s1,s2;int time;
	int idx = 1;//从1开始编号 
	while(N--){
		cin>>s1>>s2>>time;
		int a,b;
		if(mp.find(s1)==mp.end()){//如果没有出现过这个名字，赋予它数字编号 
			a = idx;
			mp.insert({s1,a});
			name[a]=s1;
			idx++;
		}
		else a = mp[s1];//否则直接从map中获得数字编号 
		if(mp.find(s2)==mp.end()){
			b = idx;
			mp.insert({s2,b});
			name[b]=s2;
			idx++;
		}
		else b = mp[s2];
		w[a]+=time; w[b]+=time;
		int na = findRoot(a);//返回根节点的编号，应当清楚Tree[na/nb] 
		int nb = findRoot(b);
		if(na!=nb){ 
			Tree[na] = nb;//na的父节点是nb 
			total[nb]+=(total[na]+time);//因此总的时间要加到total[nb]上 
			num[nb]+=num[na];//同上 
		}
		else{
			total[nb]+=time; 
		}
	}
	vector<Gang> G; 
	for(int i=1;i<=idx;i++){
		if(Tree[i]==-1&&total[i]>K&&num[i]>2){//如果帮派满足要求 
			int head = i;int maxCall = w[i];
			for(int j=1;j<=idx;j++){//寻找老大 
				if(findRoot(j)==i&&w[j]>maxCall){
					maxCall = w[j];
					head = j;
				}
			}
			G.push_back(Gang(name[head],num[i]));
		}
	}
	sort(G.begin(),G.end());
	cout<<G.size()<<endl;
	for(int i=0;i<G.size();i++){
		cout<<G[i].headName<<" "<<G[i].n<<endl;
	} 
	return 0;
}
