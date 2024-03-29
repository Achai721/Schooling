#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class A {
	public:
		string d,e;
		int o;
		void print(int N,string *id,string *n,int *s) {
			cin>>d;
			for(int j=0; j<N; j++) {
				if(d==id[j]) cout<<n[j]<<" "<<id[j]<<" "<<s[j]<<endl;
			}
		}
		void j(int N,string *id,string *n,int *s) {
			cin>>d>>e;
			for(int j=0; j<N; j++)
			{
				if(d==id[j])
				{
					n[j]=e;
				}
			}
		}
		void duichen(int N,string *id,string *n,int *s) {
			cin>>d>>o;
			for(int j=0; j<N; j++)
			{
				if(d==id[j])
				{
					s[j]=o;
				}
			}
		}
};
int main() {
	int N,M,s[101],l;
	string n[101],id[101];
	A a;
	cin>>N;

	for(int j=0; j<N; j++) {
		cin>>n[j]>>id[j]>>s[j];
	}
	cin>>M;
	for(long long i=0; i<M; i++) {
		cin>>l;
		if(l==1) a.print(N,id,n,s);
		if(l==2) a.j(N,id,n,s);
		if(l==3) a.duichen(N,id,n,s);
	}
	return 0;
}
