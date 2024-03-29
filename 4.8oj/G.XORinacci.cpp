#include <bits/stdc++.h>
using namespace std;
long long T,a, b, n;;
int main() {
    cin >> T;
    while (T--) {
        cin >> a >> b >> n;
        if (n == 0) cout << a << endl;
        else if (n == 1) cout << b << endl;
        else {
            long long c = a ^ b; // ¼ÆËã f(2)
            for (long long i = 3; i <= n; i++) {
                a = b;
                b = c;
                c = a ^ b; // ¸üÐÂ f(i)
            }
            cout << c << endl;
        }
    }
    return 0;
}
