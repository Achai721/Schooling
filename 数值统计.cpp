#include <iostream> 
using namespace std;
int main()
{
	double a,b,c,n,x;
	cin>>n;
	while(n!=0)
	{
		a=0;b=0;c=0;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			if(x<0) a++;
			if(x==0) b++;
			if(x>0) c++;
		}
		cout<<a<<" "<<b<<" "<<c<<endl;
		cin>>n; 
	} 
	return 0;
}
