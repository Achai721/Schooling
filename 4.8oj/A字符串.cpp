/*
��Ŀ����
���������ַ���a�� b,���b��a�е�һ�γ��ֵ�λ�á����bû����a�г��ֹ�,�����-1��

����
��һ�а���һ������T��ʾ��������,����ÿ������,���������ÿո�ָ����ַ���a,ֻ����Сд��ĸ��

���
����ÿ������,���b��a�е�һ�γ��ֵ�λ�á�
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
		pos = a.find(b); // ��a�в���b��һ�γ��ֵ�λ��
		if (pos == NULL) {
			cout << wu << endl;
		} else {
			cout << pos << endl;
		}
	}
	return 0;
}
