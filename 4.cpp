#include <iostream> 
#include <iomanip>
#include <cmath>
using namespace std;
struct A
{
	char c[101]; 
 } ;
int main()
{
	long long int N,K,s1,s2,x=0;
	cin>>N;
	 A shuzu[100]={
	 	{
		 }
	 };
	 int s[101],m[101];
	 
	for(int i=0;i<N;i++)
	{
		long long int r=0;
		for(int j=0;j<4;j++){
			cin>>shuzu[i].c[j];
			for(int p=0;p<8;p++)
			{
				s[p] = ((int)(shuzu[i].c[j]))%2;
				shuzu[i].c[j]/=2;
				m[7-p]=s[p]; 
			}
			x = j*8;
			for(int q=0;q<8;q++){
				r+=m[q]*pow(2,31-x);
				
				x++;
			}
			
			
		}
		cout<<r<<endl;
		r = 0;
	
		
		
	}
	return 0;
}
