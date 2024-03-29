#include<iostream>
#include<vector>
using namespace std;
int main() {
	long long t,n;
	cin>>t;
	for( long long i=0; i<t; i++) {
		cin>>n;
		long long p,q=n,m=0, a[n+1]= {};
		for( long long k=1; k<=n; k++) {
			a[k-1]=k;
		}
		while(q>=7) {
			p=0;
			while(p<7) {
				if(a[m]!=0) {//没到下报数+1 
				p++;
				if(p==7) {
						a[m]=0;//倒下 
					}
				}
				m++;
				if(m==n) {
				m=0;
			}
		}
		q--;
	}
	for(long long k=0; k<n; k++) {
			if(a[k]!=0) {
				cout<<a[k]<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
