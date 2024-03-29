#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	int a,b,n;
	double S,L,h,c;
	const double pi (3.14159265);
	cin>>a>>b>>n;
	c=n*pi/180;
	L=a+b+sqrt(a*a+b*b-2*a*b*cos(c));
	
	if(n!=90){
		S=1/2*a*b*sin(c);
	}
	else if(n==90){
		S=a*b/2;
	}
	h=2*S/a;
	
	cout<<fixed<<setprecision(8)<<S<<endl;
	cout<<fixed<<setprecision(8)<<L<<endl;
	cout<<fixed<<setprecision(8)<<h<<endl;
	return 0;
}
