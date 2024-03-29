#include <bits/stdc++.h>
#include <string>
using namespace std;


string add(string a, string b) { //高精度加法

	string res;
	int carry = 0; //进位
	int i = a.size() - 1, j = b.size() - 1;
	while (i >= 0 || j >= 0 || carry > 0) { //只要有一个数还没加完或者还有进位，就继续循环
		int x = i >= 0 ? a[i--] - '0' : 0; //如果a还没加完，就取a[i]，否则就是0
		int y = j >= 0 ? b[j--] - '0' : 0;
		int sum = x + y + carry; //当前位的和
		carry = sum / 10; //计算进位
		res = char(sum % 10 + '0') + res; //将当前位的数字转换成字符，加到res的最前面
	}
	return res;
}

string f[3001]; //f[i]表示走到第i级台阶的方法数

int main() {
	f[1] = "1";
	f[2] = "2";
	f[3] = "4";
	for (int i = 4; i <= 3000; i++) { //从第4级开始计算
		f[i] = add(add(f[i-1], f[i-2]), f[i-3]);
	}
	int n;
	while (cin >> n) {
		cout << f[n] << endl;
	}
	return 0;
}

/*方法二*/
#include<bits/stdc++.h>
using namespace std;
long long n,m=1;
int b[3004][3004];
void f(int x) { //第几个数
	for(int i=m; i>=1; i--) {
		b[x][i]=b[x-1][i]+b[x-2][i]+b[x-3][i];//计算每一位值
	}
	for(int i=m; i>=1; i--) { //进位
		if(b[x][i]>=10) {
			b[x][i+1]+=b[x][i]/10;
			b[x][i]=b[x][i]%10;
			if(b[x][m+1]!=0) { //前一位不是0
				m++;//位数
			}
		}
	}
}

int main() {
	while(cin>>n) {
		m=1;
		b[1][1]=1;
		b[2][1]=2;
		b[3][1]=4;
		for(int i=4; i<=n; i++) {
			f(i);
		}
		for(int i=m; i>0; i--) {
			cout<<b[n][i];
		}
		cout<<endl;
		for(int i=1; i<=n; i++) {
			for(int k=0; k<=m; k++) {
				b[i][k]=0;
			}
		}
	}
}

