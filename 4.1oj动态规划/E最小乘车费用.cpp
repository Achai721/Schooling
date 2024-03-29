#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int dp[101];
int m;
void shuchu() {
	for( int i=1; i<=10; i++ ) {
		cin >> dp[i];//¼ÛÖµ
	}
	cin >> m;
	for( int i=2; i<=m; i++ ) {
		for( int j=1; j<i; j++ ) {
			dp[i] = min(dp[i],dp[j]+dp[i-j]);
		}
	}
	cout << dp[m];
}
int main() {
	int w[101];
	memset(dp,0x3f3f3f3f,sizeof dp);
    shuchu();
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//
//int dp[1001];
//int n;
//int main(){
//	memset(dp,0x3f3f3f3f,sizeof dp);
//	for(int i=1;i<=10;i++){
//		cin >> dp[i];
//	}
//	cin >> n;
//	for(int i=2;i<=n;i++){
//		for(int j=1;j<i;j++){
//			dp[i] = min(dp[i],dp[j]+dp[i-j]);
//		}
//	}
//	cout << dp[n];
//	return 0;
//}

