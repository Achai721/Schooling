#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class A {
	public:
		int d,g;
		void print(string x) {
			d=x.length();
			cout<<d<<endl;
		}
		void j(string x) {
			string p;
			cin>>p;
			if(x.find(p)!=-1) {
				g=x.find(p);
				cout<<g<<endl;
			} else {
				cout<<"-1"<<endl;
			}
		}
};
int main() {
	int n,i=0,l;
	string x;
	A a;
	cin >>x;
	cin>>n;
	for (int i = 0; i < n; i++) {

	    cin>>l;
		switch (l) {
			case 1:
				a.print(x);
				break;
			case 2:
				a.j(x);
				break;
			default:
				break;
		}
	}
	return 0;
}
