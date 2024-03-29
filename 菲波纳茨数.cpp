#include <iostream>
#include<cmath>
using namespace std;
long long sz[101];
long long fib(long long x) {
	if(x==1||x==2) return 1;
	else if(sz[x]) return sz[x];
	return sz[x]=fib(x-1)+fib(x-2);
}
int main() {
	long long pi,n;
	cin>>n;
	for(long long i=0; i<n; i++) {
		cin>>pi;
		cout<<fib(pi)<<endl;
	}
	return 0;
}

