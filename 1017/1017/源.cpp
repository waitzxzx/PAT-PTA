//排队事件的模拟 
#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;
struct Window {
	int h, m, s;
	bool operator < (const Window &w)const {//按照hh:mm:ss排序 
		if (h != w.h) return h<w.h;
		if (m != w.m) return m<w.m;
		return s<w.s;
	}
};
struct Customer {
	int hh, mm, ss, time;
	bool operator < (const Customer &c)const {
		if (hh != c.hh) return hh<c.hh;
		if (mm != c.mm) return mm<c.mm;
		return ss<c.ss;
	}
};
priority_queue<Window> win;
priority_queue<Customer> cus;
int main(void) {
	int N, K;//N customers K windows
	cin >> N >> K;
	Customer c;
	for (int i = 0; i<N; i++) {
		cin >> c.hh >> ":" >> c.mm >> ":" >> c.ss >> c.time;
		cus.push(c);
	}
	Window w;
	for (int i = 0; i<K; i++) {
		w.s = w.h = 0; w.h = 8;
		win.push(w);
	}

	return 0;

}