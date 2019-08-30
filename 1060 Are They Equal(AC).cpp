/*copyright@算法笔记（胡凡，曾磊）*/
/*2018/4/15                     */
 
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int n;//有效位数
string deal(string s,int &e){
	int k=0;//s的下标
	while(s.length()>0&&s[0]=='0'){
		s.erase(s.begin());//去掉s的前导0 
	} 
	if(s[0]=='.'){
		s.erase(s.begin());//去掉前导0后是小数点,说明s是小于1的小数
		while(s.length()>0&&s[0]=='0'){
			s.erase(s.begin());//去掉小数点后非零位前的所有零
			e--;//每去掉一个零，指数e减1 
		} 
	} else{//去掉所有前导零后不是小数点，则找到后面的小数点删除 
		while(k<s.length()&&s[k]!='.'){
			k++;
			e++;//只要不碰到小数点就让指数e++ 
		}
		if(k<s.length()){//while结束后k<s.length()，说明碰到了小数点 
			s.erase(s.begin()+k);//把小数点删除 
		}
	}
	if(s.length()==0){
		e=0;//如果去掉前导零后s的长度变为0，说明这个数为0 
	}
	int num=0;
	k=0;
	string res;
	while(num<n){
		if(k<s.length())res+=s[k++];//只要还有数字，就加到res末尾
		else res+='0';//否则res末尾添加0
		num++;//精度加1 
	} 
	return res;
}
 
int main(){
	string s1,s2,s3,s4;
	cin>>n>>s1>>s2;
	int e1=0,e2=0;//e1，e2为s1与s2的指数
	s3=deal(s1,e1);
	s4=deal(s2,e2);
	if(s3==s4&&e1==e2){
		cout<<"YES 0."<<s3<<"*10^"<<e1<<endl;
	} else{
		cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;
	}
	return 0;
}
