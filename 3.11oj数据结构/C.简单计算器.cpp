#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<queue>
using namespace std;
const int N = 200;
int main() {
	double number;
	char fuhao;
	double d[N];
	while(cin >> number) {
		d[0] = number;
		int count = 0;
		while(cin >> fuhao) {
			char c = cin.get();
			if(c == '\n') {
				break;
			}
			cin >> number;
			if(fuhao == '+') {
				d[++count] = number;    //����д��++i��ԭ����+1���ٱ���ֵ����������´��������*���Ϳ������ʱcount�ϵ�ֵ���
			} else if(fuhao == '-') {    //����ȱ��棬��+1�����´�����˺ţ����Ҳ�����˵��������������Լ����п�
				d[++count] = -number;
			} else if(fuhao == '*' ) {
				d[count] *= number;
			} else if(fuhao == '/') {
				d[count] /= number;
			}

		}
		double sum = 0;
		for(int i = 0; i <= count; i++) {
			sum += d[i];
		}
		cout << fixed << setprecision(2);
		cout << sum << endl;

	}
	return 0;
}

