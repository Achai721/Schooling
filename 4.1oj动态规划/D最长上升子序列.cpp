#include<bits/stdc++.h>
#include<cstring>
using namespace std;
const int maxn=1001;


int main() {
	long long dp[maxn],a[maxn];//dp[i]��ʾ��i��β������������еĳ���
	long long n;
	cin>>n;
	memset(dp,1,n); 
	for(long long i=0; i<n; i++) {
		cin>>a[i];
		dp[i]=1;//��ʼֵ
	}
	
	for(long long i=1; i<n; i++) { //�ӵڶ�������ʼ
		for(long long j=0; j<i; j++) { //ö��ǰ�����
			if(a[j]<a[i]) //������Խ���ǰ������������к���
				dp[i]=max(dp[i],dp[j]+1);//����dp[i]
		}
	}
	long long ans=0;
	for(long long i=0; i<n; i++) {
		ans=max(ans,dp[i]);//ȡdp�����е����ֵ
	}
	cout<<ans<<endl;
	return 0;
}
