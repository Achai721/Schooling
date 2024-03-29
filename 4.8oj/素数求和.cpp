#include<iostream>
using namespace std;
bool heshu[10000001] = {0,1,0};
int main() {
	int n;
	long long sum=0;
	cin >> n;
	for (int i = 2 ; i * i <= n; i++) {
		if (heshu[i] == 0) {
			for (int j = 2; j < i; j++) {
				if (i % j == 0) {
					heshu[i] = 1;
					break;
				}
			}
			for (int k = 2; (k * i) <= n; k++) {
				heshu[k * i] = 1;
			}
		} else {
			for (int k = 2; (k * i) <= n; k++) {
				heshu[k * i] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (heshu[i] == 0) sum += i;
	}
	cout << sum;
	return 0;
}
