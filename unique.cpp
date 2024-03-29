#include<iostream>
#include<list>
using namespace std;
int main() {
	long long n,d,x;
	cin>>n;
	string m;
	list<int> l[101];
	list<int>::const_iterator it1,it2,it;
	for (long long i = 0; i < n; i++) {
		cin>>x;
		l[n].push_back(x);
		l[n].unique();
	}
	for(it=l[n].begin() ; it!=l[n].end() ; it++) {
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}

