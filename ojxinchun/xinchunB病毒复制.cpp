#include <iostream>

using namespace std;
typedef long long LL;
bool check(string a,LL len);
LL res(string s);
int main() {
	string s;
	cin >> s;
	cout << res(s) << endl;
	return 0;
}
LL res(string s) {
	LL len = s.size();
	LL result = len;
	while (len) {
		if (check(s, len)&&len!=1) {
			result = len / 2;
			len /= 2;
		} else len = 0;
	}
	return result;
}
bool check(string a,LL len) {
	int r = 0;
	for (LL i = 0, j = len - 1; i < j; i++,j--) {
		if (a[i] == a[j])r++;
	}
	if (r == len/2)return true;
	else return false;
}