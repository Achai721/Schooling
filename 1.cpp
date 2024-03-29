#include <iostream>
#include<cmath>
using namespace std;
long long fib(long long x) {
	if(x==1||x==2) return 1;
	else return fib(x-1)+fib(x-2); 
}
int main() {
	long long pi,n;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>pi;
		if(pi==1||pi==2) cout<<1<<endl;
		cout<<fib(pi)<<endl;
	}
	return 0;
}

