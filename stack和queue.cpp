#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int main() {
	stack<int> q2;
	stack<int> q3;
	queue<int> q1;
	string m;
	long long n,x,d,p,j=0;
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		for (int i = 0; i < p; i++) {
			cin >> m;
			if(m=="push") {
				cin>>x;
				q1.push(x);
				q2.push(x);
			} 
			 else {
				if(q1.empty()) {
					cout<<"error"<<endl;
					
				}
				if(q2.empty()) {
					cout<<"error"<<endl;
					
				}
				if(!q1.empty()) q1.pop();
				if(!q2.empty()) q2.pop();
			}
		}
//		if(q1.empty()== true) cout<<"error"<<endl;
		while(q1.empty()!= true) {
			cout<<q1.front()<<" ";
			q1.pop();
		}
		cout<<endl;
//		if(q2.empty()== true) cout<<"error"<<endl;
		while(q2.empty()!= true) {
			q3.push(q2.top());
			q2.pop();
		}
		while(q3.empty()!= true) {
			cout<<q3.top()<<" ";
			q3.pop();
		}
		cout<<endl;

	}
	return 0;
}


