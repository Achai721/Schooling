/*�����ظ��ַ������ִ���*/

#include <bits/stdc++.h>
#include <string.h>
using namespace std;

const int MAXN = 2e6 + 5; // ����ı�����
const int MAXM = 2e4 + 5; // ��󵥴ʳ���

char T[MAXN], W[MAXM];
int nxt[MAXM], cnt[MAXM];

void get_next() {
	int len = strlen(W);
	nxt[0] = -1;
	int i = 0, j = -1;
	while (i < len) {
		if (j == -1 || W[i] == W[j]) {
			i++, j++;
			nxt[i] = j;
		} else {
			j = nxt[j];
		}
	}
}

int kmp() {
	int t_len = strlen(T), w_len = strlen(W);
	int i = 0, j = 0, res = 0;
	while (i < t_len) {
		if (j == -1 || T[i] == W[j]) {
			i++, j++;
			if (j == w_len) { // ƥ��ɹ�
				res++;
				j = nxt[j]; // ����ƥ��
			}
		} else {
			j = nxt[j]; // ʧ�䣬��ת
		}
	}
	return res;
}

int Tcnt;

int main() {
	cin >> Tcnt;
	while (Tcnt--) {
		cin >> W >> T;
		get_next();
		cout << kmp() << endl;
	}
	return 0;
}


