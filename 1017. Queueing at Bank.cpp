//�Ŷ��¼���ģ�� 
#include<iostream>
#include<iomanip>
#include<queue>
#include<map>
using namespace std;
struct Window{//��¼������һ�ο���ʱ�� 
	int h,m,s;
	bool operator < (const Window &w)const{//����hh:mm:ss���� 
		if(h!=w.h) return h>w.h;
		if(m!=w.m) return m>w.m;
		return s>w.s;
	}
}; 
struct Customer{
	int hh,mm,ss,time;
	bool operator < (const Customer &c)const{
		if(hh!=c.hh) return hh>c.hh;
		if(mm!=c.mm) return mm>c.mm;
		return ss>c.ss;
	}
};
priority_queue<Window> win;
priority_queue<Customer> cus;
int main(void){
	int N,K;//N customers K windows
	cin>>N>>K;
	Customer c;
	for(int i=0;i<N;i++){
		cin>>c.hh;getchar();
		cin>>c.mm;getchar();
		cin>>c.ss>>c.time;
		cus.push(c);
	}
	Window w;
	for(int i=0;i<K;i++){
		w.s=w.m=0;w.h=8;
		win.push(w);
	} 
	int totalCus=0;double totalTime=0;
	while(!cus.empty()){
		c = cus.top();
		cus.pop();
		if(c.hh>=17&&(c.mm>0||c.ss>0)) break;
		totalCus++;
		
		w = win.top();
		win.pop();
		if(c.hh<w.h||(c.hh==w.h&&c.mm<w.m)||(c.hh==w.h&&c.mm==w.m&&c.ss<w.s)){
			//����˿͵����ʱ�����ڴ��ڿ���ʱ�� 
			totalTime += (w.h-c.hh)*60.0+(w.m-c.mm)+(w.s-c.ss)/60.0;
			w.m = w.m+c.time;
			w.h += w.m/60;
			w.m %= 60;
		}
		else{//����˿͵����ʱ�����ڴ��ڿ���ʱ�䣬��ʵ���ϴ����ڵȴ� 
			w.s = c.ss;
			w.m = c.mm + c.time;
			w.h += w.m/60;
			w.m %=60; 
		}
		win.push(w);
		
	}
	//cout<<totalTime<<" "<<totalCus<<endl; 
	printf("%.1f",totalTime/totalCus); 
	return 0;
}
