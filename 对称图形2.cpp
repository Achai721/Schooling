#include<iostream>
using namespace std;

int x(char a[100][100],int xbegin,int xend, int ybegin, int yend);
int y(char a[100][100], int xbegin, int xend, int ybegin, int yend);
int z(char a[100][100], int xbegin, int xend, int ybegin, int yend);
int main()
{
	int n;
	int xbegin=0, xend = 0,ybegin=100,yend=0;
	char a[100][100];
	cin >> n;
	xend = n;
	for (int i = 0; i < 100; i++)
	{
		for (int k = 0; k < 100; k++)
		{
			a[i][k] = '0';
		}
	}
	for (int i = 0; i <= n; i++)
	{
		cin.getline(a[i],100,'\n');
	}
	for (int i = 1; i <= n; i++)
	{
		for (int k = 0; k < 100; k++)
		{
			if (a[i][k] == '\0') { break; }
			else if (a[i][k] !=' '&&a[i][k] !='0')
			{
				if (k < ybegin) {
					ybegin = k;
				}
				if (k > yend) {
					yend = k;
				}
			}
		}
	}
	for (int i = n; i >= 1; i--)
	{
		for (int k = 0; k < 100; k++)
		{
			if (a[i][k] == '\0') { continue; }
			else if (a[i][k] != '0' && a[i][k] != ' ' && a[i][k] != '\0')
			{
				xend = i;
				i = 1;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int k = 0; k < 100; k++)
		{
			if (a[i][k] == '\0') { continue; }
			else if (a[i][k] != '0' && a[i][k] != ' '&& a[i][k]!='\0')
			{
				xbegin = i;
				i = n;
				break;
			}
		}
	}
	cout << x(a, xbegin, xend,ybegin,yend) + y(a, xbegin, xend, ybegin, yend) + z(a, xbegin, xend, ybegin, yend)<<endl;
	//cout << xbegin << " " << xend << " " << ybegin << " " << yend << endl;
	return 0;
}

int x(char a[100][100], int xbegin, int xend, int ybegin, int yend)
{
	if ((xbegin + xend) % 2 == 0)
	{
		int mid = (xbegin + xend) / 2;
		for (int i = xbegin; i < mid; i++)
		{
			for (int k = ybegin; k <= yend; k++)
			{
				if (a[i][k] != a[xend][k])
				{
					
					if ((a[i][k] == '\0' || a[i][k] == '0') && (a[xend][k] == ' ' || a[xend][k] == '0'))
					{
						//cout << "aaai= " << i << " k= " << k << " xend= " << xend << endl;
						continue;
					}
					else if((a[xend][k] == '\0' || a[xend][k] == '0') && (a[i][k] == ' '|| a[i][k] == '0'))
					{
						//cout << "bbbi= " << i << " k= " << k << " xend= " << xend << endl;
						continue;
					}
					else { /*cout << "ccci= " << i << " k= " << k << " xend= " << xend << endl;*/ return 0; }
				}
			}
			xend--;
		}
		return 2;
	}
	else
	{
		int mid = (xbegin + xend) / 2;
		for (int i = xbegin; i <= mid; i++)
		{
			for (int k = ybegin; k <= yend; k++)
			{
				if (a[i][k] != a[xend][k])
				{
					
					if ((a[i][k] == '\0' || a[i][k] == '0') && (a[xend][k] == ' ' || a[xend][k] == '0'))
					{
						//cout << "aaai= " << i << " k= " << k << " xend= " << xend << endl;
						continue;
					}
					else if ((a[xend][k] == '\0' || a[xend][k] == '0') && (a[i][k] == ' ' || a[i][k] == '0'))
					{
						//cout << "bbbi= " << i << " k= " << k << " xend= " << xend << endl;
						continue;
					}
					else { /*cout << "ccci= " << i << " k= " << k << " xend= " << xend << endl;*/ return 0; }
				}
			}
			xend--;
		}
		return 2;
	}
}
int y(char a[100][100], int xbegin, int xend,int ybegin, int yend)
{
	int yyend = yend;
	if ((ybegin + yend) % 2 == 0)
	{
		int midy = (ybegin + yend) / 2;
		for (int i = xbegin; i <= xend; i++)
		{
			yyend = yend;
			for (int k = ybegin; k < midy; k++)
			{
				if (a[i][k] != a[i][yyend])
				{
					
					if ((a[i][yyend] == '\0' || a[i][yyend] == '0') && (a[i][k] == ' ' || a[i][k] == '0'))
					{
						yyend--;
						continue;
					}
					else if ((a[i][k] == '\0' || a[i][k] == '0') && (a[i][yyend] == ' '|| a[i][yyend] == '0'))
					{
						yyend--;
						continue;
					}
					else
					{
						//cout << "i= " << i << " k= " << k << " yyend= " << yyend << endl;
						return 0;
					}
				}
				yyend--;
			}
		}
		return 1;
	}
	else
	{
		int midy = (ybegin + yend) / 2;
		for (int i = xbegin; i < xend; i++)
		{
			yyend = yend;
			for (int k = ybegin; k <= midy; k++)
			{
				
				if (a[i][k] != a[i][yyend])
				{
					
					if ((a[i][yyend] == '\0' || a[i][yyend] == '0') && a[i][k] == ' ')
					{
						yyend--;
						continue;
					}
					else if ((a[i][k] == '\0' || a[i][k] == '0') && a[i][yyend] == ' ')
					{
						yyend--;
						continue;
					}
					else { /*cout << "i= " << i << " k= " << k << " yyend= " << yyend << endl;*/ return 0; }
				}
				yyend--;
			}
			
		}
		return 1;
	}
}

int z(char a[100][100], int xbegin, int xend, int ybegin, int yend)
{
	int xmid;
	xmid = (xbegin + xend) / 2;
	int yybegin;
	if ((xbegin + xend) % 2 == 0)
	{
		for (int i = xbegin; i < xmid; i++)
		{
			yybegin = ybegin;
			for (int k = yend; k >=ybegin; k--)
			{
				if (a[i][k] != a[xend][yybegin])
				{
					if ((a[xend][yybegin] == '\0' || a[xend][yybegin] == '0') && a[i][k] == ' ')
					{
						yybegin++;
						continue;
					}
					else if ((a[i][k] == '\0' || a[i][k] == '0') && a[xend][yybegin] == ' ')
					{
						yybegin++;
						continue;
					}
					else { return 0; }
				}
				yybegin++;
			}
			xend--;
		}
		return 3;
	}
	else
	{
		for (int i = xbegin; i <= xmid; i++)
		{
			yybegin = ybegin;
			for (int k = yend; k >= ybegin; k--)
			{
				if (a[i][k] != a[xend][yybegin])
				{
					if ((a[xend][yybegin] == '\0' || a[xend][yybegin] == '0') && a[i][k] == ' ')
					{
						yybegin++;
						continue;
					}
					else if ((a[i][k] == '\0' || a[i][k] == '0') && a[xend][yybegin] == ' ')
					{
						yybegin++;
						continue;
					}
					else { return 0; }
				}
				yybegin++;
			}
			xend--;
		}
		return 3;
	}
}