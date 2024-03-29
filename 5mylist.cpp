#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int mylist[100];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>mylist[i];
	}
	for(int i=n;i>0;i--)
	{
		if(i==1)
		{
			cout<<mylist[i];
		}
		if(i!=1)
		{
			cout<<mylist[i]<<" ";
		}
		
	}
	
	return 0;
} 
