#include <iostream>
#include <cstring>
using namespace std;
void put(char x,int t[]){
	int u,f,r;
	switch(x){
		case 'E':
			u=7-t[2];
			f=t[1];
			r=t[0];
			break;
		case 'S':
			u=7-t[1];
			f=t[0];
			r=t[2];
			break;
		case 'W':
			u=t[2];
			f=t[1];
			r=7-t[0];
			break;
	}
	t[0]=u,t[1]=f,t[2]=r;
}
int main() {
	long long s[7],top;
	string direction;
	for(int i=1;i<=6;i++) cin>>s[i];
	cin>>direction;
	for(int i=0;i<direction.length();i++){
		top=s[1];
		if(direction[i]=='N') s[1]=s[2],s[2]=s[6],s[6]=s[5],s[5]=top;
		if(direction[i]=='S') s[1]=s[5],s[5]=s[6],s[6]=s[2],s[2]=top;
		if(direction[i]=='W') s[1]=s[3],s[3]=s[6],s[6]=s[4],s[4]=top;
		if(direction[i]=='E') s[1]=s[4],s[4]=s[6],s[6]=s[3],s[3]=top;
		top=s[1];
	}
	cout<<top<<endl;
	return 0;
}

