#include <iostream>
using namespace std;
long long triangle (long long *a,long long n) {
	long long j=0;
	for(long long i=0; i<n-2; i++){
		for(long long k=i+1; k<n-1; k++){
			for(long long l=k+1; l<n; l++){//����֮�����ڵ����� 
				if((*(a+i))+(* (a+k)) >(*(a+l))&&(*(a+i))+(* (a+l)) >(*(a+k))&&(*(a+l))+(* (a+k)) >(*(a+i)) )j++;
			}
		}
	}
	return j;
}
int main() {
	long long n;
	long long a[1001];
	cin>>n;
	for(long long i=0; i<n; i++) {
		cin>>a[i];
	}
	cout<<triangle(a,n)<<endl;//��� 
	return 0;
}
