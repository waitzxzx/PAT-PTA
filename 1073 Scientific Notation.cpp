#include<iostream>
#include<string>
using namespace std;
int string2int(string s) {//��[+-]003һ����ַ���ת������ 
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
	else if (offset > 0) {//x.xxx�����ƶ�
		int fractionLen = s.length() - 2;//С�����ֳ��� 
		s.erase(s.begin() + 1);//ȥ��С���� 
		if (fractionLen == offset) return s;
		else if (offset > fractionLen) {//��λ����С�����ֳ��� 
			s.append(offset - fractionLen, '0');//ĩβ���� 
			return s;
		}
		else {//��λС��С�����ֳ��� 
			s=s.insert(offset + 1, ".");//����С����
			//bug������ д����fractionLen-offset+1 
			return s;
		}
	}
	else {//x.xxx�����ƶ� 
		s.erase(s.begin() + 1);
		s = s.insert(0, -offset, '0');//ǰ������ 
		s = s.insert(1, ".");//��һλ���油��С���� 
		return s;
	}
}
int main(void) {
	string s;
	cin >> s;
	if (s[0] == '-') cout << "-";
	s.erase(s.begin());//ȥ������λ 
	int pos = s.find('E');
	string expStr = s.substr(pos+1, s.length()-pos-1); //���ָ�������ַ���,������E
	//cout<<expStr<<endl;
	
	s = s.erase(pos, s.length() - pos);//ɾ��ָ���������
	int exp = string2int(expStr);//���ָ�� 
	
	//cout<<exp<<endl;
	//cout<<s<<endl;
	cout << moveStr(s, exp) << endl;
	return 0;
}
