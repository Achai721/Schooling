#include<bits/stdc++.h>
using namespace std;
string pre, ino;//ǰ��������������
int pid;
void post(int l, int r) {
	int i = l;
	while (ino[i] != pre[pid]) {
		i++;
	}
	if (i> l) { //����������
		pid++;
		post(l, i - 1);
	}
	if (i <r) { //����������
		pid++;
		post(i + 1,r);
	}
	cout << ino[i];//������ڵ�
}
int main() {
	while (cin >> pre >> ino) {
		pid = 0;
		post(0, ino.length() - 1);//���ú���
		cout<<endl;
	}
	return 0;
}
