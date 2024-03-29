#include <iostream>

using namespace std;

typedef long long LL;

int main() {
	int n;
	while (cin >> n) {
		if (n == 3)cout << 1 << endl;
		else {
			LL sum = 0, a = 1;
			int b = n - 2, c = b / 2;
			if (b % 2 == 0) {
				sum = c * (a + c);
			} else if (b % 2 != 0) {
				sum = c * (a + c) + c + 1;
			}
			cout << sum << endl;
		}
	}
	return 0;
}