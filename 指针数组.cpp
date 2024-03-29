#include <iostream>
using namespace std;
void ADD(int(*a)[10],int(*b)[10],const int n)
{
    for(int m = 0;m < n;m++)
    {
        for(int l = 0;l < n;l++) {
           *(a[m]+l)=(* (a[m]+l)) +(* (b[m]+l));
        }
    }
}
int main(){
    int a[10][10],b[10][10];
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> a[i][j];
        }
    }
   for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> b[i][j];
        }
    }
    ADD(a,b,n);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout << *(a[i]+j)<< " ";
        }
        cout << endl;
    }
    return 0;
  }


