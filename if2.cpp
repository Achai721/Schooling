#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if( a < b&& b < c ){
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	else if(a>b&&b>c){
		cout<<c<<" "<<b<<" "<<a<<endl;
	}
	else if(a<c&&c<b){
		cout<<a<<" "<<c<<" "<<b<<endl;
	}
	else if(c<a&&a<b){
		cout<<c<<" "<<a<<" "<<b<<endl;
	}
	else if(b<a&&a<c){
		cout<<b<<" "<<a<<" "<<c<<endl;
	}
	else{
		cout<<b<<" "<<c<<" "<<a<<endl;
	}
	return 0;
}
