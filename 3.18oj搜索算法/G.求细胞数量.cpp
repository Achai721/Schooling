#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 205;  // 最大矩阵大小

int n, m, cnt;  // cnt表示细胞个数
int dx[4] = {-1, 0, 1, 0};  // 四个方向
int dy[4] = {0, 1, 0, -1};
bool visited[MAXN][MAXN];  // 标记数组
char matrix[MAXN][MAXN];  // 存储矩阵

void dfs(int x, int y) {
	visited[x][y] = true;  // 标记为已访问
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] != '0' && !visited[nx][ny]) {
			dfs(nx, ny);  // 从该细胞开始深度优先搜索
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> matrix[i];
	}
	memset(visited, false, sizeof(visited));  // 初始化为未访问
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] != '0' && !visited[i][j]) {  // 未访问的细胞
				cnt++;
				dfs(i, j);  // 从该细胞开始深度优先搜索
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
