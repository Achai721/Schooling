//#include <iostream>
//#include <cstring>
//using namespace std;
//
//const int MAXN = 205;  // ����Թ���С
//
//int n, m, cnt;  // cnt��ʾ���Ӹ���
//int dx[4] = {-1, 0, 1, 0};  // �ĸ�����
//int dy[4] = {0, 1, 0, -1};
//bool visited[MAXN][MAXN];  // �������
//char maze[MAXN][MAXN];  // �洢�Թ�
//
//void dfs(int x, int y) {
//	visited[x][y] = true;  // ���Ϊ�ѷ���
//	cnt++;  // ���Ӹ��Ӹ���������
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (nx >= 0 && nx < n && ny >= 0 && ny < n && maze[nx][ny] != maze[x][y] && !visited[nx][ny]) {
//			dfs(nx, ny);  // �Ӹø��ӿ�ʼ�����������
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		cin >> maze[i];
//	}
//	while (m--) {
//		int x, y;
//		cin >> x >> y;
//		x--;
//		y--;
//		memset(visited, false, sizeof(visited));  // ��ʼ��Ϊδ����
//		cnt = 0;
//		dfs(x, y);  // �Ӹø��ӿ�ʼ�����������
//		cout << cnt << endl;
//	}
//	return 0;
//}
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1005;
int n, m;
int maze[MAXN][MAXN];
bool vis[MAXN][MAXN];

// bfs��������
int bfs(int x, int y) {
	queue<pair<int, int> > q; // ������У�pair<int, int> ��ʾ����
	q.push({x, y}); // ��������
	int res = 0; // ��¼�ܵ���ĸ�����������ʼΪ0
	vis[x][y] = true; // ���Ϊ�ѷ���
	while (!q.empty()) { // ���зǿ���ѭ��
		pair<int, int> p = q.front(); // ȡ������Ԫ��
		q.pop(); // ��������Ԫ��
		int cx = p.first, cy = p.second; // ��ǰ����
		res++; // ������һ�����ӣ�������һ
		// �����ĸ����������仯����
		int dx[4] = {-1, 0, 1, 0};
		int dy[4] = {0, 1, 0, -1};
		// �����ĸ�����
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			// ��������겻Խ����δ�����ʹ����ǿ��Ե���ĸ��ӣ���Ӳ����Ϊ�ѷ���
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && maze[nx][ny] != maze[cx][cy]) {
				q.push({nx, ny});
				vis[nx][ny] = true;
			}
		}
	}
	return res;
}

int main() {
	cin >> n >> m;
	// �����Թ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			maze[i][j] = c - '0';
		}
	}
	// ����ѯ��
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		memset(vis, false, sizeof(vis)); // ��ʼ��vis����
		cout << bfs(x-1, y-1) << endl; // ����ܵ���ĸ�������
	}
	return 0;
}
