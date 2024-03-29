#include<iostream>
#include<deque>
#include <algorithm>
using namespace std;

int main()
{
	int n,m,d,x;
	deque<int> dq;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		if(m==0) {
			cin>>d>>x;
			if(d==0) dq.push_front(x);
			if(d==1) dq.push_back(x);
		}
		else if(m==1) {
			cin>>d;cout<<dq[d]<<endl;
		}
		else {
			cin>>d;
			if(d==0) dq.pop_front();
			if(d==0) dq.pop_back();
		}
	}
	return 0;
}

