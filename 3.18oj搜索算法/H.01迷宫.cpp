//#include <iostream>
//#include <cstring>
//using namespace std;
//
//const int MAXN = 205;  // 最大迷宫大小
//
//int n, m, cnt;  // cnt表示格子个数
//int dx[4] = {-1, 0, 1, 0};  // 四个方向
//int dy[4] = {0, 1, 0, -1};
//bool visited[MAXN][MAXN];  // 标记数组
//char maze[MAXN][MAXN];  // 存储迷宫
//
//void dfs(int x, int y) {
//	visited[x][y] = true;  // 标记为已访问
//	cnt++;  // 增加格子个数计数器
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (nx >= 0 && nx < n && ny >= 0 && ny < n && maze[nx][ny] != maze[x][y] && !visited[nx][ny]) {
//			dfs(nx, ny);  // 从该格子开始深度优先搜索
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
//		memset(visited, false, sizeof(visited));  // 初始化为未访问
//		cnt = 0;
//		dfs(x, y);  // 从该格子开始深度优先搜索
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

// bfs搜索函数
int bfs(int x, int y) {
	queue<pair<int, int> > q; // 定义队列，pair<int, int> 表示坐标
	q.push({x, y}); // 把起点入队
	int res = 0; // 记录能到达的格子总数，初始为0
	vis[x][y] = true; // 标记为已访问
	while (!q.empty()) { // 队列非空则循环
		pair<int, int> p = q.front(); // 取出队首元素
		q.pop(); // 弹出队首元素
		int cx = p.first, cy = p.second; // 当前坐标
		res++; // 搜索到一个格子，总数加一
		// 定义四个方向的坐标变化数组
		int dx[4] = {-1, 0, 1, 0};
		int dy[4] = {0, 1, 0, -1};
		// 遍历四个方向
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			// 如果新坐标不越界且未被访问过且是可以到达的格子，入队并标记为已访问
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
	// 读入迷宫
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			maze[i][j] = c - '0';
		}
	}
	// 处理询问
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		memset(vis, false, sizeof(vis)); // 初始化vis数组
		cout << bfs(x-1, y-1) << endl; // 输出能到达的格子总数
	}
	return 0;
}
