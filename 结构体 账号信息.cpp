#include <iostream> 
using namespace std;
int main()
{
	int n;
	cin>>n;
	struct A
	{
		string user;
		string password;
	 } ;
	 for(int i=0;i<n;i++)
	 {
	 	A a;
	 	cin>>a.user>>a.password;
	 	cout<<a.user<<" "<<a.password<<endl;
	 }
	return 0;
}
