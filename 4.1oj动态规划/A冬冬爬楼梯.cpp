#include <bits/stdc++.h>
#include <string>
using namespace std;


string add(string a, string b) { //�߾��ȼӷ�

	string res;
	int carry = 0; //��λ
	int i = a.size() - 1, j = b.size() - 1;
	while (i >= 0 || j >= 0 || carry > 0) { //ֻҪ��һ������û������߻��н�λ���ͼ���ѭ��
		int x = i >= 0 ? a[i--] - '0' : 0; //���a��û���꣬��ȡa[i]���������0
		int y = j >= 0 ? b[j--] - '0' : 0;
		int sum = x + y + carry; //��ǰλ�ĺ�
		carry = sum / 10; //�����λ
		res = char(sum % 10 + '0') + res; //����ǰλ������ת�����ַ����ӵ�res����ǰ��
	}
	return res;
}

string f[3001]; //f[i]��ʾ�ߵ���i��̨�׵ķ�����

int main() {
	f[1] = "1";
	f[2] = "2";
	f[3] = "4";
	for (int i = 4; i <= 3000; i++) { //�ӵ�4����ʼ����
		f[i] = add(add(f[i-1], f[i-2]), f[i-3]);
	}
	int n;
	while (cin >> n) {
		cout << f[n] << endl;
	}
	return 0;
}

/*������*/
#include<bits/stdc++.h>
using namespace std;
long long n,m=1;
int b[3004][3004];
void f(int x) { //�ڼ�����
	for(int i=m; i>=1; i--) {
		b[x][i]=b[x-1][i]+b[x-2][i]+b[x-3][i];//����ÿһλֵ
	}
	for(int i=m; i>=1; i--) { //��λ
		if(b[x][i]>=10) {
			b[x][i+1]+=b[x][i]/10;
			b[x][i]=b[x][i]%10;
			if(b[x][m+1]!=0) { //ǰһλ����0
				m++;//λ��
			}
		}
	}
}

int main() {
	while(cin>>n) {
		m=1;
		b[1][1]=1;
		b[2][1]=2;
		b[3][1]=4;
		for(int i=4; i<=n; i++) {
			f(i);
		}
		for(int i=m; i>0; i--) {
			cout<<b[n][i];
		}
		cout<<endl;
		for(int i=1; i<=n; i++) {
			for(int k=0; k<=m; k++) {
				b[i][k]=0;
			}
		}
	}
}

