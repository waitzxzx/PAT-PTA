/*copyright@�㷨�ʼǣ����������ڣ�*/
/*2018/4/15                     */
 
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int n;//��Чλ��
string deal(string s,int &e){
	int k=0;//s���±�
	while(s.length()>0&&s[0]=='0'){
		s.erase(s.begin());//ȥ��s��ǰ��0 
	} 
	if(s[0]=='.'){
		s.erase(s.begin());//ȥ��ǰ��0����С����,˵��s��С��1��С��
		while(s.length()>0&&s[0]=='0'){
			s.erase(s.begin());//ȥ��С��������λǰ��������
			e--;//ÿȥ��һ���㣬ָ��e��1 
		} 
	} else{//ȥ������ǰ�������С���㣬���ҵ������С����ɾ�� 
		while(k<s.length()&&s[k]!='.'){
			k++;
			e++;//ֻҪ������С�������ָ��e++ 
		}
		if(k<s.length()){//while������k<s.length()��˵��������С���� 
			s.erase(s.begin()+k);//��С����ɾ�� 
		}
	}
	if(s.length()==0){
		e=0;//���ȥ��ǰ�����s�ĳ��ȱ�Ϊ0��˵�������Ϊ0 
	}
	int num=0;
	k=0;
	string res;
	while(num<n){
		if(k<s.length())res+=s[k++];//ֻҪ�������֣��ͼӵ�resĩβ
		else res+='0';//����resĩβ���0
		num++;//���ȼ�1 
	} 
	return res;
}
 
int main(){
	string s1,s2,s3,s4;
	cin>>n>>s1>>s2;
	int e1=0,e2=0;//e1��e2Ϊs1��s2��ָ��
	s3=deal(s1,e1);
	s4=deal(s2,e2);
	if(s3==s4&&e1==e2){
		cout<<"YES 0."<<s3<<"*10^"<<e1<<endl;
	} else{
		cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;
	}
	return 0;
}
