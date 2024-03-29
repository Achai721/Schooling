#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main() {
	long long n;
	cin>>n;
	string a;
	long long h,x,y,b=0,c=0,d,s=0,m,k;
	for(long long i=0; i<n; i++) {
		cin>>a>>h>>x>>y;
		d=(x-b)*(x-b)+(y-c)*(y-c);
		s+=(int)pow(d,0.5);
		if(i<3) {
			m=h;
			k=1;
			while(m>0) {
				m=h-30*k;
				k++;
			}
			s+=k-1;
		}

		else if(i<8) {
			m=h;
			k=1;
			while(m>1) {
				m=h-40*k;
				k++;
			}
			s+=k-1;
		} else {
			m=h,k=1;
			while(m>0) {
				m=h-55*k;
				k++;
			}
			s+=k-1;
		}
		b=x,c=y;
	}
	cout<<s<<endl;
}
