#include <iostream>
#include<cmath>
using namespace std;
long long wan(long long x) {
	long long s=0;
	for(long long i=1; i<x; i++) {
		if(x%i==0) s+=i;
	}
	return s==x;
}
int main() {
	long long p,q,n;
	cin>>n;
	while(cin>>p>>q) {
		long long j=0;
		for(long long i=p; i<=q; i++) {
			if(wan(i)==1) {
				j++;
			}
		}
		cout<<j<<endl;
	}
	return 0;
}

