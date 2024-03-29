#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	double x[n+1]={};
	double y[n+1]={};
	double c,sum1=0,sum2=0,sum3=0,max=0;
	for(long long int i=0;i<2;i++){
		for(long long int m=0;m<n;m++)
		{
		    if(i==0)cin>>x[m];
		   	else cin>>y[m];
		}

	}
	for(long long int i=0;i<n;i++){
		c=fabs(x[i]-y[i]);
		if(c>max)max=c;
		sum1+=c;
	}

	for(long long int i=0;i<n;i++){
		c=pow(fabs(x[i]-y[i]),2);
		sum2+=c;
		
	}
	for(long long int i=0;i<n;i++){
		c=pow(fabs(x[i]-y[i]),3);
		sum3+=c;
	}
	cout<<fixed<<setprecision(6)<<sum1<<endl;
	cout<<fixed<<setprecision(6)<<pow(sum2,0.5)<<endl;
	cout<<fixed<<setprecision(6)<<pow(sum3,0.333333333)<<endl;
	cout<<fixed<<setprecision(6)<<max<<endl; 
	return 0;
} 
