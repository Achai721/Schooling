//#include <bits/stdc++.h>
//using namespace std;
//const int N = 405;
//int n, m, sx, sy;
//int dist[N][N]; // dist[i][j]��ʾ����(i, j)����С����
//bool vis[N][N]; // ����Ƿ���ʹ���λ��
//int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2}; // ������ߵİ˸�����
//int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
//
//void bfs() {
//	queue<int> q; // �洢�����ʵ�λ��
//	q.push({sx, sy}); // �����������
//	vis[sx][sy] = true;
//	while (!q.empty()) {
//		auto [x, y] = q.front();
//		q.pop();
//		for (int i = 0; i < 8; i++) { // ö�ٰ˸�����
//			int nx = x + dx[i], ny = y + dy[i];
//			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny]) { // �ж��Ƿ�Խ����Ƿ���ʹ�
//				vis[nx][ny] = true;
//				dist[nx][ny] = dist[x][y] + 1; // ���µ����λ�õ���С����
//				q.push({nx, ny}); // ����λ�ü������
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m >> sx >> sy;
//	memset(dist, -1, sizeof(dist)); // ��ʼ��Ϊ-1
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

const int MAXN = 405; // ������̴�С
const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1}; // ������ߵİ˸�����
const int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int n, m, sx, sy, ans[MAXN][MAXN]; // ans[i][j]��ʾ���(sx, sy)����(i, j)�����ٲ���

struct Node {
	int x, y, step;
};

void bfs() {
	memset(ans, -1, sizeof(ans)); // ��ʼ��Ϊ-1
	queue<Node> q;
	q.push({sx, sy, 0});
	ans[sx][sy] = 0; // ��㵽���ľ���Ϊ0
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

