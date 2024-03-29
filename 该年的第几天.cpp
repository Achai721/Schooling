#include <iostream>
#include <cmath>
using namespace std;
long long x(long long n) {
	if(n%4==0&&n%100!=0)  {
		return 1;
	} else if(n%400==0) {
		return 1;
	} else {
		return 0;
	}
}
int main() {
	long long m,n,p,r;
	cin>>m;
	char a;
	for(long long i=0; i<m; i++) {
		cin>>n>>a>>p>>a>>r;
		long long d=0;
		if(p==1) {
			d=r;
		} else if(x(n)==0) {
			for(long long k=1; k<p; k++) {
				if(k==2) {
					d=d+28;
				}

				else if(k==1||k==3||k==5||k==7||k==8||k==10||k==12) {
					d=d+31;
				} else {
					d=d+30;
				}
			}
			d=d+r;
		} else {
			for(long long k=1; k<p; k++) {
				if(k==2) {
					d=d+29;
				} else if(k==1||k==3||k==5||k==7||k==8|k==10||k==12) d=d+31;
					else d=d+30;
					}
			d+=r;
		}
		cout<<d<<endl;
	}
	return 0;
}
