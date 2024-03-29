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
		cin >> m;
		if(m=="new") {
			cin>>d;
		} else if(m=="add") {
			cin>>d>>x;
			l[d].push_back(x);
		} else if(m=="merge") {
			cin>>d>>x;
			for(it2=l[x].begin(); it2!=l[x].end() ; it2++){
			    l[d].push_back(*it2);
			}
			l[x].clear() ;
		} else if(m=="unique") {
			cin>>d;
			l[d].unique();
		} else {
			cin>>d;
			l[d].sort();
			for(it=l[d].begin() ; it!=l[d].end() ; it++) {
				cout<<*it<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

