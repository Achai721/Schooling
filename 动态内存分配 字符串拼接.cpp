#include <iostream>
#include<cstring>
using namespace std;
char* cat_fun(const char* stra, const char* strb);
int main() {
	char stra[20], strb[20];
	cin >> stra >> strb;
	cout << cat_fun(stra, strb) << endl;
	return 0;
}
char* cat_fun(const char* stra, const char* strb)
{
	int i = 0;
	int len1 = strlen(stra);
	int len2 = strlen(strb);
	char * h = new char[1000];
	while (i<len1)
	{
		*(h + i) = *stra;
		i++;
		stra++;
	}
	while (i < len2+len1)
	{
		*(h + i) = *strb;
		i++;
		strb++;
	}
	*(h + i) = { 0 };
	return h;
	delete [] h;
}
