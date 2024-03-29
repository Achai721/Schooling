#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void f(long long n) { 
	long long a[101];
	long long i = n, j = 0,m=1,p;
	while(i) {
		a[j] = i % 2;
		i /= 2;
		j++;
	}
	for (p = 0; p <j; p++) {
        if(a[p]!=a[j-p-1]) 
        {
        	cout<<"No"<<endl;
        	m=0;
        	break;
		}
	}
	if(m==1) cout<<"Yes"<<endl;
}
int main() {
	long long T,n;
	cin>>T;
	for(long long i=0; i<T; i++) {
		cin>>n;
		f(n);
	}
	return 0;
}
