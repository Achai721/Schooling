//1.查找价值最大的并且不超重的  2.用m-价值最大的那个  3.求总价值 4.找价值第二大的重复上述过程 ，比较大小，作为最优解
//5.找价值第三大的重复，最终比较完所有解得到最优解

#include<iostream>
#include<algorithm>
using namespace std;
int dp[1009];
int main() {
	int n, m;
	int w[1009], p[1009];
	cin >> m >> n;//总质量和总物品数 
	for( int i=1; i<=n; i++ ) {
		cin >> w[i] >> p[i];//质量和价值 
	}
	for( int i=1; i<=n; i++ ) {
		for( int j=m; j>=w[i]; j-- ) {
			dp[j] = max(dp[j], dp[j-w[i]] + p[i]);
		}
	}
	cout << dp[m];
	return 0;
}


