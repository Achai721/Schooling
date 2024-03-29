#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	while(n!=0)
	{
		long long int a[n+1]={};
		long long sum=0;
		double avg,fang=0,biao,g;
		for(long long int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}	
		avg=sum/n;
		for (long long int i = 0; i < n; i++)
		{
			fang += pow(a[i] - avg, 2);
		}
		g=fang/n;
		biao=sqrt(g);
		cout<<fixed<<setprecision(8)<<biao<<endl;
		cin>>n;
	}
	return 0;
} 
