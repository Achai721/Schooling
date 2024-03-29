//#include <iostream>
//#include<cstring>
//using namespace std;
//char* re(const char* stra);
//int main() {
//	char stra[20];
//	cin >> stra;
//	cout << re(stra) << endl;
//	return 0;
//}
//char* re(const char* stra) {
//	int len1 = strlen(stra);
//	int a=0;
//	char * h = new char[len1];
//	for (long long i=0; i<=len1; i++) {
//		*(h + i) = *(stra+len1-i-1);
//		a=i;
//	}
//	*(h + a) = { 0 };
//	return h;
//}
#include<iostream>
#include<cstring>
using namespace std;

void count(int N,int a[],string b[],int c[]);
void zhuanhuan(int c[], string b[]);
int main()
{
	int a[] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 },c[13];
	string b[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	int N;
	cin >> N;
	count(N, a, b, c);
	zhuanhuan(c, b);
	return 0;
}
void count(int N, int a[], string b[],int c[])
{
	for (int i = 0; i < 13; i++)
	{
		if (N / a[12-i] != 0)
		{
			c[12-i] = N / a[12-i];
			N %= a[12-i];
		}
		else
		{
			c[12 - i] = 0;
		}
	}
}
void zhuanhuan(int c[], string b[])
{
	for (int i = 12; i >=0; i--)
	{
		if (c[i]!=0)
		{
			for (int j = 0; j < c[i]; j++)
			{
				cout << b[i];
			}
		}
	}
}

