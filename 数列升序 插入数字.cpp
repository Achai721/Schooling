
 #include <iostream>
#include <algorithm>
#include <string> 
int a[100];
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            
        }
        int min=a[0],b;
        for (int i = 0; i < n; i++) {
            if (min>= a[i]) {
                min = a[i];
                b = i;
                
            }
            
        }
        a[b] = a[0];
        a[0] = min;
        for (int i = 0; i < n; i++)
        cout << a[i] << " ";
        cin >> n;
        
    }
    return 0;
}
