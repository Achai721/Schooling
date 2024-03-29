#include <iostream> 
using namespace std;
int main()
{
	int n,T,x;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int a[6]={0};
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			a[i]=x;
		}	
		for(int i=0;i<n;i++)
		{
			int b;
			b=a[i];
		}
		for(int i=0;i<n;i++)
		{
			if(a[i]==0||a[i]%2==0) a[i]=1;
		}
		long long int w=1;
		for(int i=0;i<n;i++)
		{
			w*=a[i];
		}
		cout<<w<<endl;
	}
	return 0;
}
