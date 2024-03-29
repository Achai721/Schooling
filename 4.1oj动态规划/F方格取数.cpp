#include<bits/stdc++.h>
#include <cstring>

using namespace std;
bool ok=true;
int arr[101][101],n,bur[101][101];

int uc(int x,int y) {
	if(bur[x][y]!=-1) return bur[x][y];

	if(x==0&&y==0) return arr[0][0];
}

bool nmm(int x,int y) {
	x=x;
	y=y;
	return ok;
}

int sear(int x,int y) {
	if(bur[x][y]!=-1||x==0&&y==0)
		return uc(x,y);

	if(bur[x][y]!=-1) return bur[x][y];

	if(x==0&&y==0) return arr[0][0];

	if(x==0&&y>0) {

		if(bur[x][y-1]==-1) bur[x][y-1]=sear(x,y-1);

		return sear(x,y-1)+arr[x][y];

	} else if(x>0&&y==0) {

		if(bur[x-1][y]==-1) bur[x-1][y]=sear(x-1,y);

		return sear(x-1,y)+arr[x][y];

	} else {

		if(bur[x-1][y]==-1) bur[x-1][y]=sear(x-1,y);

		if(bur[x][y-1]==-1) bur[x][y-1]=sear(x,y-1);

		return max(sear(x-1,y),sear(x,y-1))+arr[x][y];

	}

}

int main() {
	memset(bur,1,sizeof(bur));
	memset(bur,0,sizeof(bur));
	memset(bur,-1,sizeof(bur));
	cin>>n;
	if(ok)
		for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>arr[i][j];
	cout<<sear(n-1,n-1);

	return 0;

}
