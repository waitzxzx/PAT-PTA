#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
char name[40010][5];
bool cmp(int a,int b){//NEW ������Ŷ�Ӧ�������ַ���������Ž������� 
    if(strcmp(name[a],name[b])<0) return true;
    else return false;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<vector<int> > v(n+1);
    for(int i=0;i<n;i++){
        scanf("%s",name[i]);                
        int cnt;
        scanf("%d",&cnt);
        for(int j=0;j<cnt;j++){
            int k;
            scanf("%d",&k);
            v[k].push_back(i);
        }
    }
    for(int i=1;i<=k;i++){
        printf("%d %d\n",i,(int)v[i].size());
        sort(v[i].begin(),v[i].end(),cmp);//�Լ�¼ѡ��ѧ����ŵ�vector���� 
		for(int j=0;j<v[i].size();j++) {
            printf("%s\n",name[v[i][j]]);
        }
    }
    return 0;
} 
