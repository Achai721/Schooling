#include<bits/stdc++.h>
#include<cstring>
using namespace std;
const int maxn=1001;


int main() {
	long long dp[maxn],a[maxn];//dp[i]表示以i结尾的最长上升子序列的长度
	long long n;
	cin>>n;
	memset(dp,1,n); 
	for(long long i=0; i<n; i++) {
		cin>>a[i];
		dp[i]=1;//初始值
	}
	
	for(long long i=1; i<n; i++) { //从第二个数开始
		for(long long j=0; j<i; j++) { //枚举前面的数
			if(a[j]<a[i]) //如果可以接在前面的上升子序列后面
				dp[i]=max(dp[i],dp[j]+1);//更新dp[i]
		}
	}
	long long ans=0;
	for(long long i=0; i<n; i++) {
		ans=max(ans,dp[i]);//取dp数组中的最大值
	}
	cout<<ans<<endl;
	return 0;
}
