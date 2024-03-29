#include <iostream> 
using namespace std;
struct A
{
	long long int shi[101];
	long long int xv[101];
 } ;
int main()
{
	long long int N,K,s1,s2;
	cin>>N;
	cin>>K; 
	s1=0;
	s2=0;
	 A shuzu[100]={
	 	{
		 }
	 };
	 int i=0;
	 while(i<N)
	 {
	 	for(int j=0;j<K;j++)
	 	{
	 		cin>>shuzu[i].shi[j]>>shuzu[i].xv[j];
	 		s1+=shuzu[i].shi[j];
	 	    s2+=shuzu[i].xv[j];
		}
		cout<<s1<<" "<<s2<<endl;
		cin>>K;
		i++;
		s1=0;
		s2=0;
	 }
	return 0;
}
