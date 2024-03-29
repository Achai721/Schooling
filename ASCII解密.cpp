#include <iostream>
#include<cstring>
using namespace std;
char *s(char*m)
{
	int l = strlen(m);
	for(int i=0;i<l;i++)
	{
		int n = *(m+i);
		if(n<=90&&n>=69)
		{
			*m=(char)(n-4);

		}
		else if(n>=65&&n<=68)
		{
			*m=(char)n+22;
		}
		cout<<*m;
	}

	return m;
}
int main()
{
	char a[101];
	cin>>a;
	s(a);
	return 0;
 } 
