#include<iostream>
#include<algorithm>
using namespace std;
int searchytou(char a[101][101],int n) ;
int searchyhou(char a[101][101],int n) ;
int sxzhou(char a[101][101], int xtou, int xhou, int ytou, int yhou) ;
int main() {
	char a[101][101];
	int n,xhou,xtou,ytou=101,yhou=0;
	cin>>n;
	for (int i=0; i<=n; i++) {
		cin.getline(a[i],100,'\n');                                       //输入
	}
	ytou=searchytou(a,n);
	yhou=searchyhou(a,n);
	for(int i=n; i>=1; i--) {
		for(int k=0; k<101; k++) {
			if(a[i][k]=='\0') continue;
			else if (a[i][k]!= ' '&&a[i][k]!='\0'&&a[i][k] !='0') {
				xhou=i;
				i=1;
				break;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int k=0; k<101; k++) {
			if(a[i][k]=='\0') continue;
			else if (a[i][k]!= ' '&&a[i][k]!='\0'&&a[i][k] !='0') {
				xtou=i;
				i=n;
				break;
			}
		}
	}
	int yzhou=1;//y轴
	int yy=yhou;
	int hao=yhou-ytou;
	int qi=ytou+yhou;
	if (hao%2!=0) {
		int ymid=qi/2;
		int h=xtou;
		while(h<=xhou) {
			yy=yhou;
			int g=ytou;
			while(g<=ymid) {
				if (a[h][g]!=a[h][yy]) {
					if ((a[h][g] == '\0') && (a[h][yy] == ' ')) {
						yy--;
						continue;
					} else if((a[h][yy] == '\0') && (a[h][g] == ' ')) {
						yy--;
						continue;
					} else  yzhou=0;
				}
				yy--;
				g++;
			}
			h++;
		}
	} else if(hao%2==0) {
		int ymid=qi/2;
		int m=xtou;
		while(m<=xhou) {
			yy=yhou;
			int v=ytou;
			while( v<ymid) {

				if (a[m][v]!=a[m][yy]) {
					if ((a[m][v] == '\0') && (a[m][yy] == ' '||a[m][yy]== '0')) {
						yy--;
						continue;
					} else if((a[m][yy] == '\0') && (a[m][v] == ' '||a[m][v]=='0')) {
						yy--;
						continue;
					} else  yzhou=0;
				}
				yy--;
				v++;
			}
			m++;
		}
	}
	int xzhou=sxzhou(a,xtou,xhou,ytou,yhou);
	int z=3;//中心对称
	int Y=ytou;
	int fan=xtou+xhou;
	int aaa=xhou-xtou;
	int xmid=fan/2;
	int u=xtou;
	int rr=xtou;
	switch(aaa%2) {
		case 0:
			while(u<xmid) {
				Y=ytou;
				int q=yhou;
				while(q>=ytou) {
					if (a[u][q]!=a[xhou][ytou]) {
						if ((a[u][q] == '\0') && (a[xhou][Y]==' ')) {
							Y++;
							continue;
						} else if((a[xhou][Y]=='\0') && (a[u][q] == ' ')) {
							Y++;
							continue;
						} else  z=0;
					}
					Y++;
					q--;
				}
				xhou--;
				u++;
			}
			break;
		case 1:
			while(rr<=xmid) {
				Y=ytou;
				int k=yhou;
				while(k>=ytou) {
					if (a[rr][k]!=a[xhou][Y]) {
						if ((a[rr][k] == '\0') && (a[xhou][Y] == ' ')) {
							Y++;
							continue;
						} else if((a[xhou][Y] == '\0') && (a[rr][k] == ' ')) {
							Y++;
							continue;
						} else  z=0;
					}
					Y++;
					k--;
				}
				xhou--;
				rr++;
			}
			break;	
			default: break;
	}
	cout<<xzhou+yzhou+z<<endl;//计算得分
	return 0;
}
int searchytou(char a[101][101],int n) {
	int ytou=101;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<101; j++) {
			if(a[i][j]=='\0') break;
			else if (a[i][j]!=' '&&a[i][j] !='0') {
				if (j<ytou) ytou=j;
			}
		}
	}
	return ytou;
}
int searchyhou(char a[101][101],int n) {
	int yhou=0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<101; j++) {
			if(a[i][j]=='\0') break;
			else if (a[i][j]!=' '&&a[i][j] !='0') {
				if (j>yhou) yhou=j;
			}
		}
	}
	return yhou;
}
int sxzhou(char a[101][101], int xtou, int xhou, int ytou, int yhou) {
	if ((xtou + xhou) % 2 == 0) {
		int mid = (xtou + xhou) / 2;
		for (int i = xtou; i < mid; i++) {
			for (int k = ytou; k <= yhou; k++) {
				if (a[i][k] != a[xhou][k]) {
					if ((a[i][k] == '\0' || a[i][k] == '0') && (a[xhou][k] == ' ' || a[xhou][k] == '0')) {
						continue;
					} else if((a[xhou][k] == '\0' || a[xhou][k] == '0') && (a[i][k] == ' '|| a[i][k] == '0')) {
						continue;
					} else {
						return 0;
					}
				}
			}
			xhou--;
		}
		return 2;
	} else {
		int mid = (xtou + xhou) / 2;
		for (int i = xtou; i <= mid; i++) {
			for (int k = ytou; k <= yhou; k++) {
				if (a[i][k] != a[xhou][k]) {
					if ((a[i][k] == '\0' || a[i][k] == '0') && (a[xhou][k] == ' ' || a[xhou][k] == '0')) {
						continue;
					} else if ((a[xhou][k] == '\0' || a[xhou][k] == '0') && (a[i][k] == ' ' || a[i][k] == '0')) {
						continue;
					} else {
						return 0;
					}
				}
			}
			xhou--;
		}
		return 2;
	}
}
