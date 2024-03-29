#include <iostream> 
using namespace std;
struct A
{
	long long int zi1;
	long long int mu1;
	long long int zi2;
	long long int mu2;
 } ;
int y(int q, int p)
{
	int f,n;
	if(q<p)
	{
		f=q;p=q;p=f;
	}
	while(p%q!=0)
	{
		n=q;
		q=p%q;
		p=n; 
	}
	return q;
 } 
int main()
{
	long long int N,s1,s2;
	long int x=1;
	cin>>N;
	 A shuzu[100]={
	 	{
		 }
	 };
	 for(int i=0;i<N;i++)
	 {
	 	cin>>shuzu[i].zi1>>shuzu[i].mu1>>shuzu[i].zi2>>shuzu[i].mu2;
	 }
	for(int i=0;i<N;i++)
    {
		s1=shuzu[i].zi1*shuzu[i].mu2+shuzu[i].zi2*shuzu[i].mu1;
	 	s2=shuzu[i].mu1*shuzu[i].mu2;
		if(s1%s2==0&&s2!=1)
		{
			cout<<s1/s2<<" "<<1<<endl;
		}
		else 
		{
			x=y(s2,s1);
			s1/=x;
			s2/=x;
			cout<<s1<<" "<<s2<<endl;
		}
	}
	
	return 0;
}
