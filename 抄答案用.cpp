for(long long i=0;i<n;i++){
//		long long s=nums[i];
		dp[i]=nums[i];
		for(long long k=i+1;k<n;k++){
//			s+=nums[k];
			dp[i]=max(dp[i],nums[i]+nums[k]);
		}
		ans=max(ans,dp[i]);
	}
