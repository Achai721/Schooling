#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class A {
	public:
		long long x,y,r;
		void print(long long x,long long y) {
			cout<<x<<" "<<y<<endl;
		}
		void j(long long x,long long y,long long r) {
			double h=acos(-1);
			cout<<fixed<<setprecision(8)<<h*r*r<<endl;
		}
		void duichen(long long x,long long y,long long r) {
			double h=acos(-1);
			cout<<fixed<<setprecision(7)<<2*h*r<<endl;
		}
		void yuan(long long x,long long y,long long r) {
			long long p,q,r1,s,juli;
			cin>>p>>q>>r1;
			s=(x-p)*(x-p)+(y-q)*(y-q);
			juli=sqrt(s);
			if(sqrt(s)==r-r1 || sqrt(s)==r+r1 || sqrt(s)==r1-r)
		    {
				cout<<"Yes"<<endl;
			}
			else 
			{
			    cout<<"No"<<endl;	
			}
		}
};
int main() {
	long long x,y,n,l,r,p,q,p2,q2;
	A a;
	cin>>x>>y>>r;
	cin>>n;
	for(long long i=0; i<n; i++) {
		cin>>l;
		if(l==1) a.print(x,y);
		else if(l==2) a.j(x,y,r);
		else if(l==3) a.duichen(x,y,r);
		else a.yuan(x,y,r);
	}
	return 0;
}
