#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int W,H,x,y,r;
	cin>>W>>H>>x>>y>>r;
	if(y+r<=H&&r<=y&&x+r<=W&&x>=r){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}
