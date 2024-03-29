#include <iostream> 
#include <iomanip>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int i=0;
	while(a!=0||b!=0||c!=0)
	{
		for(i==0;i<=b-a;i++)
		{
			if(c%a==0){
			i++; 
			}
			cin>>a>>b>>c;
			a++;
		}
	}
	return 0;
 } 
