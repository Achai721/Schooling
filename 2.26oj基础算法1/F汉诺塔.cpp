#include <iostream>
using namespace std;
long long h(long long n){
	long long x=0;
	for(long long i=0;i<n;i++){//利用公式递归 
		x=2*x+1;
	}
	return x;
}
int main(){
	long long T,n;
	cin>>T;
	for(long long i=0;i<T;i++){
		cin>>n;
		cout<<h(n)<<endl; 
	}
	return 0;
} 
