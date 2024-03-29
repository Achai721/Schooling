#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
const int INF=-10001;//定义负无穷
const int maxn=105;

int main() {
	long long n;
	int a[maxn][maxn];
	int sum[maxn];
	int dp[maxn];//a数组存储原始数据，sum数组存储前缀和
	while(cin>>n) {
		memset(a,0,sizeof(a));//每组数据初始化
		long long ans=INF;//ans存储最大子矩阵和，初始化为负无穷
		for(long long i=0; i<n; i++) {
			for(long long j=0; j<n; j++) {
				cin>>a[i][j];
			}
		}
		for(long long i=0; i<n; i++) {
			memset(sum,0,sizeof(sum));
			memset(dp, 0 ,sizeof(dp));

			//枚举所有可能的子矩阵
			for(long long j=i; j<n; j++) {
				for(long long k=0; k<n; k++) {
					sum[k]+=a[j][k];
				}
				dp[0]=sum[0];
				for(long long i=1; i<n; i++) {
					dp[i]=max(sum[i],dp[i-1]+sum[i]);
				}
				long long k=0;
				for(long long i=1; i<n; i++)
					if(dp[i]>dp[k])k=i;
				if(ans<dp[k])ans=dp[k];
			}
		}
		cout<<ans<<endl;//输出最大子矩阵和
	}
	return 0;
}
