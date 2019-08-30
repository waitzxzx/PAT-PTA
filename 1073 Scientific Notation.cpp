#include<iostream>
#include<string>
using namespace std;
int string2int(string s) {//把[+-]003一类的字符串转成数字 
	bool isNeg = false;
	if (s[0] == '-') isNeg = true;
	s.erase(s.begin());
	int ans = 0;
	for (int i = 0; i<s.length(); i++) {
		ans = ans * 10 + s[i] - '0';
	}
	if (isNeg) return -ans;
	else return ans;
}
string moveStr(string s, int offset) {
	if (offset == 0) return s;
	else if (offset > 0) {//x.xxx向右移动
		int fractionLen = s.length() - 2;//小数部分长度 
		s.erase(s.begin() + 1);//去掉小数点 
		if (fractionLen == offset) return s;
		else if (offset > fractionLen) {//移位大于小数部分长度 
			s.append(offset - fractionLen, '0');//末尾补零 
			return s;
		}
		else {//移位小于小数部分长度 
			s=s.insert(offset + 1, ".");//加上小数点
			//bug！！！ 写成了fractionLen-offset+1 
			return s;
		}
	}
	else {//x.xxx向左移动 
		s.erase(s.begin() + 1);
		s = s.insert(0, -offset, '0');//前方补零 
		s = s.insert(1, ".");//第一位后面补上小数点 
		return s;
	}
}
int main(void) {
	string s;
	cin >> s;
	if (s[0] == '-') cout << "-";
	s.erase(s.begin());//去除符号位 
	int pos = s.find('E');
	string expStr = s.substr(pos+1, s.length()-pos-1); //获得指数部分字符串,不包括E
	//cout<<expStr<<endl;
	
	s = s.erase(pos, s.length() - pos);//删除指数这个部分
	int exp = string2int(expStr);//获得指数 
	
	//cout<<exp<<endl;
	//cout<<s<<endl;
	cout << moveStr(s, exp) << endl;
	return 0;
}
