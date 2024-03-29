#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	int b[100];
	for(int i=0;i<=100;i++)
	{
		
		int x;
		for(int i=0;i<100;i++)
		{
			cin>>x;
			b[i]=x;
		}
		int min=x;
		if(x<min) min=x;
		swap(min,x);
		
	}
	cout<<b[100]<<endl;
	return 0;
 } 
