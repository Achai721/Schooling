//1.���Ҽ�ֵ���Ĳ��Ҳ����ص�  2.��m-��ֵ�����Ǹ�  3.���ܼ�ֵ 4.�Ҽ�ֵ�ڶ�����ظ��������� ���Ƚϴ�С����Ϊ���Ž�
//5.�Ҽ�ֵ��������ظ������ձȽ������н�õ����Ž�

#include<iostream>
#include<algorithm>
using namespace std;
int dp[1009];
int main() {
	int n, m;
	int w[1009], p[1009];
	cin >> m >> n;//������������Ʒ�� 
	for( int i=1; i<=n; i++ ) {
		cin >> w[i] >> p[i];//�����ͼ�ֵ 
	}
	for( int i=1; i<=n; i++ ) {
		for( int j=m; j>=w[i]; j-- ) {
			dp[j] = max(dp[j], dp[j-w[i]] + p[i]);
		}
	}
	cout << dp[m];
	return 0;
}


