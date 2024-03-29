#include <iostream>
using namespace std;
int main() {
	long int n,max,min,sum=0,a;
	cin>>n;
	cin>>a;
	min=a;max=a;
	for(int i=1;i<n;i++){
		sum+=a;
		if(a>max) max=a;
		if(a<min) min=a;
		cin>>a;
	}
	sum+=a;
	if(a>max) max=a;
	if(a<min) min=a;
	cout<<min<<" "<<max<<" "<<sum;
	return 0;
}

