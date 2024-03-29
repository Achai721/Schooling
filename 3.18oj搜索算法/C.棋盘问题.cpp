#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
char board[10][10];
bool column[10];
int ans;

//DFS���
void dfs(int row, int cnt) {
	if(cnt == k) { //�ҵ�һ���
		ans++;
		return;
	}
	if(row == n) return; //�������
	dfs(row + 1, cnt); //��������
	for(int col = 0; col < n; col++) {
		if(!column[col] && board[row][col] == '#') { //���Է�����
			column[col] = true;
			dfs(row + 1, cnt + 1);
			column[col] = false;
		}
	}
}

int main() {
	while(cin >> n >> k) {
		if(n == -1 && k == -1) break;
		memset(column, false, sizeof(column));
		ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		dfs(0, 0);
		cout << ans << endl;
	}
	return 0;
}

