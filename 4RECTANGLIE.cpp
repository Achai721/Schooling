#include <iostream>
using namespace std;
int main() {
	int W,H;
	while(true){
		cin>>H>>W;
		if(H==0 && W==0)
		{
			break;
		}
		for(int i=1;i<=H;i++)
		{
			for(int j=1;j<=W;j++)
			{
				if((i+j)%2==0)
				{
					cout<<"#";
				}
				else
				{
					cout<<".";
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
