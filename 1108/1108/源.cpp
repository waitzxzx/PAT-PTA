#include<iostream>
#include<string>
using namespace std;
double n = 0;
bool isLegal(string s) {
	bool isNeg = false;
	if (s[0] == '-') {
		isNeg = true;
		s.erase(s.begin());
	}
	bool hasPoint = false;
	n = 0;
	int i = 0;
	double p = 0;
	int cnt = 0;
	for (int i = 0; i<s.length(); i++) {
		if (s[i] >= '0'&&s[i] <= '9') {
			if (!hasPoint) {
				i = 10 * i + (s[i] - '0');
			}
			else if (hasPoint&&cnt<2) {
				cnt++;
				if (cnt == 1) p = 0.1*(s[i] - '0');
				else if (cnt == 2) p += 0.01*(s[i] - '0');
			}
			else {
				return false;
			}
		}
		else if (i != 0 && s[i] == '.' && !hasPoint) {
			hasPoint = true;
		}
		else {
			return false;
		}
	}
	cout << p << " " << i << endl;
	if (isNeg) n = -p - i;
	else n = p + i;
	if (n <= 1000.0&&n >= -1000.0) return true;
	else return false;
}
int main(void) {
	int N; cin >> N;
	int cnt = 0; double sum = 0;
	string s; 
	for (int i = 0; i<N; i++) {
		cin >> s; n = 0;
		if (isLegal(s)) {
			cnt++;
			cout << n << endl;
			sum += n;
		}
		else {
			cout << "ERROR: " << s << " is not a legal number" << endl;
		}
	}
	cout << "The average of " << cnt << " numbers is ";
	if (cnt == 0) cout << "Undefined" << endl;
	else {
		printf("%.2f\n", sum / cnt);
	}
}