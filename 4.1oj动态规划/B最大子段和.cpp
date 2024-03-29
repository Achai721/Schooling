#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long M;
	cin >> M;
	while (M--) {
		long long n;
		cin >> n;
		long long* nums = new long long[n+1];
		for (long long i = 0; i < n; i++) {
			cin >> nums[i];
		}
		long long* dp = new long long[n+1];
		dp[0] = nums[0];
		long long ans = 0;

		for(long long i=1; i<n; i++) {
			long long s=nums[i];
			dp[i]=nums[i];
			for(long long k=i+1; k<n; k++) {
				s+=nums[k];
				dp[i]=max(dp[i],s);
			}
			ans=max(ans,dp[i]);
		}

		cout << ans << endl;
		delete[] nums;
		delete[] dp;
	}
	return 0;
}
