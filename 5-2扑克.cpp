#include<iostream>
#include<iomanip> 
using namespace std;
int main()
{
    int n,num,S[14],H[14],C[14],D[14];
    char a;
    cin >> n;
    for(int i= 0; i< n; i++)
    {
    	cin >>a>> num;
        if (a == 'S'){ S[num] = num;}
        if (a == 'H') {H[num] = num;}
        if (a=='C') {C[num] = num;}
        if (a == 'D') {D[num]= num;}
	}
	for(int j = 1;j < 14;j++)
	{
	    if (S[j] != j) { cout << 'S'<<" "<<j<<endl;}
    }
    for(int k = 1;k < 14;k++)
	{
	    if (H[k] != k) { cout << 'H'<<" "<<k<<endl;}
    }
    for(int l = 1;l < 14;l++)
	{
	    if (C[l] != l) { cout << 'C'<<" "<<l<<endl;}
    }
    for(int m = 1;m < 14;m++)
	{
	    if (D[m] != m) { cout << 'D'<<" "<<m<<endl;}
    }
    return 0;
}
