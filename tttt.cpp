#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int maxn = 10050;
int n, m, k;
int input[maxn], check[maxn];
int vis[maxn];
 
bool isPrime(int x) {
	if (x <= 1)
		return false;
	else {
		for (int i = 2; i*i <= x; i++) {
			if (x%i == 0) {
				return false;
			}
		}
	}
	return true;
}
 
int main() {
	scanf("%d%d%d", &n, &m, &k);
	while (!isPrime(n)) {
		n++;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &input[i]);
		int num = input[i];
		bool flag = true;
		for (int j = 0; j < n; j++) {
			num = (input[i] + j*j) % n;
			if (vis[num] == 0) {
				vis[num] = input[i];
				flag = false;
				break;
			}
		}
		if (flag) {
			printf("%d cannot be inserted.\n", input[i]);
		}
	}
	double sum = 0.0;
	for (int i = 0; i < k; i++) {
		scanf("%d", &check[i]);
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			int num = (check[i] + j*j) % n;
			if (vis[num] == check[i] || vis[num] == 0)
				break;
			cnt++;
		}
		cout<<cnt<<endl;
		sum += cnt;
	}
	printf("%.1lf\n", sum / k);
	return 0;
}
