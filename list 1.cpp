#include<iostream>
#include<list>
using namespace std;
int main() {
	long long n,d,x,p,m;
	cin>>n>>p;
	list<int> q[101];
	list<int>::const_iterator it;
	for (long long i = 0; i < p; i++) {
		cin >> m;
		if(m==0) {
			cin>>d>>x;
			q[d].push_back(x);
		}
		else if(m==1) {
			cin>>d;
			for(it=q[d].begin();it!=q[d].end();it++){
				cout<<*it<<" "; 
			}
			cout<<endl;
		}
		else {
			cin>>d>>x;
			q[x].insert(q[x].end(),q[d].begin(),q[d].end());
			q[d].clear();
		}
	}
	return 0;
}

