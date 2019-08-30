#include<iostream>
#include<string>
using namespace std;
int string2int(string s) {
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
		int fractionLen = s.length() - 2;
		if (fractionLen == offset) {
			s.erase(s.begin() + 1); return s;
		}
		else if (offset > fractionLen) {
			s.erase(s.begin() + 1);
			s.append(offset - fractionLen, '0');
			return s;
		}
		else {
			s.erase(s.begin() + 1);
			s=s.insert(fractionLen - offset + 1, ".");
			return s;
		}
	}
	else {
		s.erase(s.begin() + 1);
		s = s.insert(0, -offset, '0');
		s = s.insert(1, ".");
		return s;

	}
}
int main(void) {
	string s, ans;
	cin >> s;
	if (s[0] == '-') cout << "-";
	s.erase(s.begin());
	//找到指数
	int pos = s.find('E');
	string expStr = s.substr(pos, s.length() - pos); //指数部分字符串 
	s = s.erase(pos, s.length() - pos);//删除这个部分
	expStr.erase(expStr.begin());
	int exp = string2int(expStr);
	cout << moveStr(s, exp) << endl;
	getchar();
	getchar();
	return 0;
}