#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	long long n,m,l=0;
	cin>>n>>m;
	long long a[3*m+3]= {},b[n+3]= {},s[n+3]= {},g[n+3]= {};
	for(long long i=1; i<=3*m+1; i++) {
		cin>>a[i];
		b[a[i]]++;
	}
	sort ( a+1 ,a+ 3 *m+1+1);
	long long q=1;
	for ( long long i= 1; i<= n ; i++ ) {
		long long d ;
		for( long long j=1; j<=n; j++) {
			d= 0 ;
			long long h= 0 ;
			for ( long long k=1 ; k<=n+2 ; k++ ) {
				s [ k ]=b[ k ] ;
				if(k==i) {
					s [ k ]++;
				}
				if(k==j) {
					s [ k ] -= 2;
				}
				if(s [ k ]<0 ) {
					h= 1;
				}
			}
			d= h ;
			if( h==0 ) {
				for ( long long k = 1; k<=n+ 2 ; k++ ) {
					if( s[ k ]<0 ) {
						d = 1;
						break ;
					}
					s [ k ] =s [ k ] % 3 ;
					s [ k+1] =s [ k+1] -s[ k ];
					s [ k+2]=s [ k+2 ] -s [ k ] ;
				}
			}
			if ( d==0 ) {
				break ;
			}
		}
		if( d== 0 ) {
			g[ ++l]=i;
			q= d ;
		}
	}
	if( q==1) {
		cout<<"NO"<<endl;
	} else {
		for ( long long i= 1; i<=l; i++) {
			cout<<g[i]<<" " ;
		}
		cout<<endl ;
	}
	return 0;
}
