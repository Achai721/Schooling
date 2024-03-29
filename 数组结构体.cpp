#include <iostream> 
using namespace std;
struct A
{
	long long int student_id;
	string name;
	long int score;
 } ;
int main()
{
	long long int N,Q,n;
	cin>>N;
	 A shuzu[100];

	 for(int i=0;i<N;i++)
	 {
	 	cin>>shuzu[i].student_id>>shuzu[i].name>>shuzu[i].score;
	 }
	cin>>Q;
	for(int i=0;i<Q;i++)
	{
	 	cin>>n;
	 	if(n==shuzu[i].student_id)
	 	{
	 		cout<<shuzu[i].name<<" "<<shuzu[i].score<<endl;
		}
	}
	 
	return 0;
}
