#include <iostream>
using namespace std;
int sushu(int m) {
	for (int n = 2; n <= m / n; n++)
		if (m % n == 0)return 1;
	return 0;
}
int main() {
	int n,sum=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		if(sushu(i)==1) {
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
