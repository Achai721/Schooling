#include <iostream> 
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double a,b,c;
	cin>>a>>b>>c;
	cout<<fixed<<setprecision(2)<<fabs(a)+fabs(b)+fabs(c)<<endl;
	return 0;
}
