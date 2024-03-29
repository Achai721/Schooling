#include <iostream>
using namespace std;
int p(int x)
{
	int number=x;
	int m=0;
	while(number>0)
	{
		m=m*10+number%10;
		number/=10;
	}
	return m==x;
} 
int main()
{
	for(int i=11;i<1000;i++)
	{
		if(p(i)&&p(i*i)&&p(i*i*i))
		{
			cout<<i<<endl;
		}
	}
	return 0;
}
