#include <iostream>
using namespace std;
int a[4][3][10];
int main(){
	int n,b,f,r,v;
	cin >> n;
	while (n > 0) {
		n--;
		cin >> b >> f >> r>>v;
		a[b-1][f-1][r-1] += v;
	}
	for (int b = 0; b < 4; b++) {
		for (int f = 0; f < 3; f++) {
			cout << " ";
			for (int r = 0; r < 10; r++) {
				cout << a[b][f][r]<<" ";
				}
			cout << endl;
			if (f==2&&b!=3) {
				for (int i = 0; i < 20; i++) cout << "#";
				cout<<endl;
	         }
		}
	}
	return 0;
}
