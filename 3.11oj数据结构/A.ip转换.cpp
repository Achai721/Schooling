#include<bits/stdc++.h>
using namespace std;
long long x(long long j) {//������תʮ����
	long long m=1;
	while(j>0) {
		m=m*2;
		j--;
	}
	return m;
}
int main() {
	long long n;
	cin>>n;
	long long a[33]= {};//33λ
	string b;
	for(long long i=0; i<n; i++) {
		cin>>b;
		for(long long j=0; j<b.size(); j++) {
			a[j]=b[j]-'0';//�ַ���ת����
		}
		long long k=0;
		while(k<4) {
			long long s=0;
			for(long long j=7; j>=0; j--) {
				s+=a[k*8+7-j]*x(j);//�������תʮ���ƣ�ÿһλ�ֱ����Ӧ�Ķ���j�η����������
			}
			if(k==3) cout<<s<<endl;
			else cout<<s<<".";
			k++;
		}
	}
}
