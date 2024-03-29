#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
char board[10][10];
bool column[10];
int ans;

//DFS求解
void dfs(int row, int cnt) {
	if(cnt == k) { //找到一组解
		ans++;
		return;
	}
	if(row == n) return; //搜索完毕
	dfs(row + 1, cnt); //不放棋子
	for(int col = 0; col < n; col++) {
		if(!column[col] && board[row][col] == '#') { //可以放棋子
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

