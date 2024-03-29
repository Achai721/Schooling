#include <iostream>
#include<cmath>
using namespace std;
long long p(long long x) {
	long long s=0,j,y=x;
	while(y!=0){
		j=y%10;
		s+=pow(j,3);
		y/=10;
	}
	return s==x;
}
int main(){
	long long m,n;
	while(cin>>m>>n) {
		long long j=m-1;
		for(long long i=m; i<=n; i++) {
			if(p(i)!=0) {
				cout<<i<<" ";
			} 
			else{
				j++;
			}
		}
		if(j==n) {
			cout<<"no";
		}
		cout<<endl;
	}
}

