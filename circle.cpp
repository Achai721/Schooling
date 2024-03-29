#include <iostream> 
#include <iomanip>
#include <cmath> 
using namespace std;
const double pi=acos(-1);
int main()
{
	int r;
	cin>>r;
	cout<<fixed<<setprecision(6)<<pi*r*r<<" "<<fixed<<setprecision(6)<<2*pi*r<<endl;
	return 0;
}
