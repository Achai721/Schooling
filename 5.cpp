#include <iostream> 
using namespace std;
int main()
{
	int s;
	cin>>s;
	int hh,mm,ss;
	hh=s/3600;
	mm=(s%3600)/60;
	ss=s%3600%60;
	cout<<hh<<":"<<mm<<":"<<ss<<endl;
	return 0;
}
