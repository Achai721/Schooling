#include <iomanip>
#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
	int n,a[1001],b[1001];
	while(cin>>n) {
		for(int i=0; i<n; i++) {
			cin>>a[i];
			b[i]=fabs(a[i]);//��B�����A����
		}
		sort(b,b+n);//���� 
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(b[i]==fabs(a[j])) {
					b[i]=a[j];//ȥ����ֵ
				}
			}
		}
		for(int i=n-1; i>=0; i--) cout<<b[i]<<" ";
	}
	return 0;
}
