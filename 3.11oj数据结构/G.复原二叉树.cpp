#include<bits/stdc++.h>
using namespace std;
string pre, ino;//前序遍历，中序遍历
int pid;
void post(int l, int r) {
	int i = l;
	while (ino[i] != pre[pid]) {
		i++;
	}
	if (i> l) { //遍历左子树
		pid++;
		post(l, i - 1);
	}
	if (i <r) { //遍历右子树
		pid++;
		post(i + 1,r);
	}
	cout << ino[i];//处理根节点
}
int main() {
	while (cin >> pre >> ino) {
		pid = 0;
		post(0, ino.length() - 1);//调用函数
		cout<<endl;
	}
	return 0;
}
