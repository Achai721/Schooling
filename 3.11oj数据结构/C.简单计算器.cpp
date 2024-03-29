#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<queue>
using namespace std;
const int N = 200;
int main() {
	double number;
	char fuhao;
	double d[N];
	while(cin >> number) {
		d[0] = number;
		int count = 0;
		while(cin >> fuhao) {
			char c = cin.get();
			if(c == '\n') {
				break;
			}
			cin >> number;
			if(fuhao == '+') {
				d[++count] = number;    //这里写成++i的原因，先+1，再保存值，这样如果下次输入符号*，就可以与此时count上的值相乘
			} else if(fuhao == '-') {    //如果先保存，再+1，则下次输入乘号，他找不到相乘的数。还不懂，自己运行看
				d[++count] = -number;
			} else if(fuhao == '*' ) {
				d[count] *= number;
			} else if(fuhao == '/') {
				d[count] /= number;
			}

		}
		double sum = 0;
		for(int i = 0; i <= count; i++) {
			sum += d[i];
		}
		cout << fixed << setprecision(2);
		cout << sum << endl;

	}
	return 0;
}

