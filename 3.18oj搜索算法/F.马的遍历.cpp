//#include <bits/stdc++.h>
//using namespace std;
//const int N = 405;
//int n, m, sx, sy;
//int dist[N][N]; // dist[i][j]表示马到达(i, j)的最小步数
//bool vis[N][N]; // 标记是否访问过该位置
//int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2}; // 马可以走的八个方向
//int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
//
//void bfs() {
//	queue<int> q; // 存储待访问的位置
//	q.push({sx, sy}); // 将起点加入队列
//	vis[sx][sy] = true;
//	while (!q.empty()) {
//		auto [x, y] = q.front();
//		q.pop();
//		for (int i = 0; i < 8; i++) { // 枚举八个方向
//			int nx = x + dx[i], ny = y + dy[i];
//			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny]) { // 判断是否越界和是否访问过
//				vis[nx][ny] = true;
//				dist[nx][ny] = dist[x][y] + 1; // 更新到达该位置的最小步数
//				q.push({nx, ny}); // 将该位置加入队列
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m >> sx >> sy;
//	memset(dist, -1, sizeof(dist)); // 初始化为-1
//	dist[sx][sy] = 0;
//	bfs();
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << dist[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int MAXN = 405; // 最大棋盘大小
const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1}; // 马可以走的八个方向
const int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int n, m, sx, sy, ans[MAXN][MAXN]; // ans[i][j]表示马从(sx, sy)到达(i, j)的最少步数

struct Node {
	int x, y, step;
};

void bfs() {
	memset(ans, -1, sizeof(ans)); // 初始化为-1
	queue<Node> q;
	q.push({sx, sy, 0});
	ans[sx][sy] = 0; // 起点到起点的距离为0
	while (!q.empty()) {
		Node node = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = node.x + dx[i];
			int ny = node.y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && ans[nx][ny] == -1) {
				ans[nx][ny] = node.step + 1;
				q.push({nx, ny, node.step + 1});
			}
		}
	}
}

int main() {
	cin >> n >> m >> sx >> sy;
	bfs();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

