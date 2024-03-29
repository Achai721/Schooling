#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
long int p(long int x,long int n)
{
	long int result=1;
	for(long int i=1;i<=n;i++)
	{
		result*=x;
	}
	return result;
}
int main()
{
	long int x,n;
	cin>>x>>n;
	while(x!=-1&&n!=-1)
	{
		cout<<p(x,n)<<endl;
		cin>>x>>n;
	}
	return 0;
}
