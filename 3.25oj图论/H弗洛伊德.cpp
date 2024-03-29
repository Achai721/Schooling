#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 55;
const int INF = 0x3f3f3f3f;

int n, m;
int g[MAXN][MAXN]; // 存储图的邻接矩阵
int dist[MAXN][MAXN]; // 存储每个点到其他点的最短距离

void floyd() {
	// 初始化
	memcpy(dist, g, sizeof(g));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				dist[i][j] = 0;
			} else if (dist[i][j] == 0) { // 若i到j没有直接边，则初始化为INF
				dist[i][j] = INF;
			}
		}
	}

	// floyd算法
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] != INF && dist[k][j] != INF) { // 判断是否存在中转点k
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> g[i][j];
		}
	}

	floyd();

	// 输出结果
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) {
				cout << -1 << " ";
			} else {
				cout << dist[i][j] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}

