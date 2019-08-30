#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 2007;
int Tree[MAX];
int w[MAX];//ÿ����Ա��Ȩ�� 
int total[MAX];//���ɵ�Ȩ�� 
int num[MAX];//�������� 
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
map<string,int> mp;//���ڱ�ź�����֮���໥ת�� 
int main(void){
	int N,K;cin>>N>>K;
	for(int i=1;i<=MAX;i++){//memset�����Ը�ֵ1 ������ 
		num[i]=1;
	}
	memset(Tree,-1,sizeof(Tree));
	memset(w,0,sizeof(w));
	memset(total,0,sizeof(total)); 
	string s1,s2;int time;
	int idx = 1;//��1��ʼ��� 
	while(N--){
		cin>>s1>>s2>>time;
		int a,b;
		if(mp.find(s1)==mp.end()){//���û�г��ֹ�������֣����������ֱ�� 
			a = idx;
			mp.insert({s1,a});
			name[a]=s1;
			idx++;
		}
		else a = mp[s1];//����ֱ�Ӵ�map�л�����ֱ�� 
		if(mp.find(s2)==mp.end()){
			b = idx;
			mp.insert({s2,b});
			name[b]=s2;
			idx++;
		}
		else b = mp[s2];
		w[a]+=time; w[b]+=time;
		int na = findRoot(a);//���ظ��ڵ�ı�ţ�Ӧ�����Tree[na/nb] 
		int nb = findRoot(b);
		if(na!=nb){ 
			Tree[na] = nb;//na�ĸ��ڵ���nb 
			total[nb]+=(total[na]+time);//����ܵ�ʱ��Ҫ�ӵ�total[nb]�� 
			num[nb]+=num[na];//ͬ�� 
		}
		else{
			total[nb]+=time; 
		}
	}
	vector<Gang> G; 
	for(int i=1;i<=idx;i++){
		if(Tree[i]==-1&&total[i]>K&&num[i]>2){//�����������Ҫ�� 
			int head = i;int maxCall = w[i];
			for(int j=1;j<=idx;j++){//Ѱ���ϴ� 
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
