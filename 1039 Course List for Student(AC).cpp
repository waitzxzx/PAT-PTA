#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >hashTable((int)1e6);//�洢��Ӧ�����ָ����ѧ��ѡ�Ŀ�,ɢ������Ĵ�С����Ҫ����һ��
int strhash(const string&s){
    int k=0;
    for(int i=0;i<3;++i)
        k=k*26+s[i]-'A';
    k=k*26+s[3]-'0';
    return k;
}
int main(){
    int N,K;
    string name;
    scanf("%d%d",&N,&K);
    for(int i=1;i<=K;++i){
        int course,num;
        scanf("%d%d",&course,&num);
        while(num--){
            cin>>name;
            hashTable[strhash(name)].push_back(course);//�ø������µ�vector�洢ѡ�Ŀ�
        }
    }
    while(N--){
        cin>>name;
        int k=strhash(name);//������ɢ��Ϊһ������
        printf("%s %d",name.c_str(),hashTable[k].size());//��Ҫ�����
        sort(hashTable[k].begin(),hashTable[k].end());
        for(int i=0;i<hashTable[k].size();++i)
            printf(" %d",hashTable[k][i]);
        printf("\n");
    }
    return 0;
}
