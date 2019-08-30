#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >hashTable((int)1e6);//存储相应编号所指代的学生选的课,散列数组的大小尽量要开大一点
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
            hashTable[strhash(name)].push_back(course);//让该整数下的vector存储选的课
        }
    }
    while(N--){
        cin>>name;
        int k=strhash(name);//将名字散列为一个整数
        printf("%s %d",name.c_str(),hashTable[k].size());//按要求输出
        sort(hashTable[k].begin(),hashTable[k].end());
        for(int i=0;i<hashTable[k].size();++i)
            printf(" %d",hashTable[k][i]);
        printf("\n");
    }
    return 0;
}
