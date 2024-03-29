# include<iostream>
#include<string>
#include<iomanip>
using namespace std ;
int main( ) {
	long long a , m;
	while( scanf( "%d " ,&a ) &&a!=0 ) {
		double n=0.0 ,q [ 1000 ]= { } ;
		char c , s ;
		m = 0 ;
		q [ ++m] =1.0* a ;
		while( scanf( "%c  %lf%c " , &c , &n , &s ) !=EOF) {
			if ( c== '+' ) {
				q [ ++m ]=n ;
			} else if( c== '-' ) {
				q [ ++m] =-1*n ;
			} else if ( c== '*' ) {
				q[m]=q [ m ] *n ;
			} else if(c== '/') {
				q[m] =q[m ] / n ;
			}
			if ( s != ' ' ) {
				break ;
			}
		}
		double b=0 ;
		for ( long long i=1 ; i<=m ; i++) {
			b+=q [ i];
		}
		cout<<fixed<<setprecision ( 2)<<b<<endl;

	}
	return 0;
}
