/*
题目描述
给定连个字符串a和 b,求出b在a中第一次出现的位置。如果b没有在a中出现过,则输出-1。

输入
第一行包含一个数字T表示样例个数,对于每组样例,包含两个用空格分隔的字符串a,只包含小写字母。

输出
对于每组样例,输出b在a中第一次出现的位置。
*/
#include <bits/stdc++.h>
#include <string>
using namespace std;
long long n,pos;
long long wu=-1;

int main() {
	cin >> n;
	while (n--) {
		string a, b;
		cin >> a >> b;
		pos = a.find(b); // 在a中查找b第一次出现的位置
		if (pos == NULL) {
			cout << wu << endl;
		} else {
			cout << pos << endl;
		}
	}
	return 0;
}
