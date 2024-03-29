// Write a program which reads two integers a and b, and calculates the following values:a ¡Â b: d (in integer)  remainder of a ¡Â b: r (in integer)  a ¡Â b: f (in real number)
#include <iostream> 
#include <iomanip>
using namespace std;
int main()
{
	int T,x,y;
	long long int p,q;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		p=0;q=0;
		cin>>x>>y;
		for(int i=x;i<y+1;i++)
		{
			if(i%2==0)
			{
				p+=i*i;
			}
			else
			{
				q+=i*i*i;
			}
		}
		cout<<p<<" "<<q<<endl;
    }
	return 0;
}
