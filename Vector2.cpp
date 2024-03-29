#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector< vector<int> > v;
	int i,n,a,t, x;
	cin >> i >> n;
	for (int j = 0; j < i; j++) {
		v.push_back(vector<int>());
	}
	for (int i = 0; i < n; i++) {
		cin >> a;
		if(a==0) {
			cin >> t >> x;
			v[t].push_back(x);
		}
		if(a==1) {
			cin >> t;
			for (int j = 0; j < v[t].size(); j++) {
				cout << v[t][j] << " ";
			}
			cout << endl;
		}
		if(a==2) {
			cin >> t;
			v[t].clear();
		}
	}
	return 0;
}

//}
