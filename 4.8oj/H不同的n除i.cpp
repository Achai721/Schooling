/*
��Ŀ����
����һ��n������i��1��n���ҳ��ж��ٸ���ͬ��n/i
�磺n=6
��4����ͬ��n/i��6��3��2��1
����
��һ��һ��T����ʾ��T������(T < 100000)
֮��T�У�ÿ��һ��n(n <= 10^18)
���
ÿ�����һ��������ʾ��ͬ�ĸ���
*/
#include<bits/stdc++.h>
using namespace std;
long long m,n;
int main() {
	cin>>n;
	while(n--) {
		cin>>m;
		long long pou=sqrt(m+1);
		for(long long i=pou; i<=m; i++) {
			long long jian=i*(i-1);
			long long jia=i*(i+1);//�жϵڼ��� 
			if(m+1>jian&&m+1<=jia) {  //�ж�ǰ��κ��� 
				if(m+1-jian<=i) {
					cout<<2*i-2<<endl;
				} else {
					cout<<2*i-1<<endl;
				}
				break;
			}
		}
	}
}
//0 0
//1 1           2 4 6 
//23 2
//45 3
//678 4
//91011 5  
