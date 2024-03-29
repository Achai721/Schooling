#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int y(int q, int p) {
	int f,n;
	if(q>p) {
		f=q;
		p=q;
		p=f;
	}
	while(p%q!=0) {
		n=q;
		q=p%q;
		p=n;
	}
	return q;
}
int main() {
	int a,b,gbs,gys;
	while(cin>>a>>b) {
		gys=y(a,b);
		gbs=a*b/gys;
		cout<<gbs<<endl;
	}
	return 0;
}
