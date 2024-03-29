#include <iostream>
#include <queue>
using namespace std;
int main(){
	priority_queue<int> q[101];
	int n,m,x,d,p;
	cin >> n>>p;
	for (int i = 0; i < p; i++)
	{
		cin >> m;
		if(m==0) {
			cin>>d>>x;
			q[d].push(x);
		}
		else if(m==1) {
			cin>>d;cout<<q[d].top()<<endl;
		}
		else {
			cin>>d;
			q[d].pop();
		}
	}
	return 0;
}

