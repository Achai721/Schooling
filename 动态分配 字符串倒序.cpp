#include <iostream>
#include<cstring>
using namespace std;
char* re(const char* stra);
int main() {
	char stra[20];
	cin >> stra;
	cout << re(stra) << endl;
	return 0;
}
char* re(const char* stra) {
	int len1 = strlen(stra);
	int a=0;
	char * h = new char[len1];
	for (long long i=0; i<=len1; i++) {
		*(h + i) = *(stra+len1-i-1);
		a=i;
	}
	*(h + a) = { 0 };
	return h;
}
//#include <iostream>
//#include<cstring>
//using namespace std;
//
//
//char* str_reverse(const char* str) {
//    int len = strlen(str);
//    int a;
//    char* p = new char[len];
//    for (int i = 0; i <= len; i++)
//    {
//        *(p + i) = *(str + len - i-1);
//        a = i;
//    }
//    *(p + a) = { 0 };
//    return p;
//    delete[]p;
//}
//
//
//int main()
//{
//    char str[100];
//    cin >> str;
//    cout << str_reverse(str);
//    return 0;
//}
