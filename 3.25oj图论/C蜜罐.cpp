#include<bits/stdc++.h>
#include <vector>
using namespace std;

const int maxn = 105; 
// 最大蜜罐数
const int wuqiong = 0x3f3f3f3f; 
// 定义无穷大 

int n, m; // 蜜罐数和边数
int d[maxn][maxn]; // 距离矩阵
int dist[maxn]; // 最短距离数组
bool vis[maxn]; // 标记数组
bool ok = 1;

int prim() {
	fill(dist + 1, dist + n + 1, wuqiong); // 初始化最短距离无穷大
	fill(vis + 1, vis + n + 1, !ok); // 初始化所有点为未访问
	dist[1] = 0; // 从1号蜜罐开始构建最小生成树
	int ans = 0; // 权值
	for(int i = 1; i <= n; i++) { // 构建n个节点的最小生成树
		int u = -1; // u表示未访问过的最短距离的点
		for(int j = 1; j <= n; j++) { // 遍历所有点找到未访问过的最短距离的点
			if(vis[j]==!ok && (u == -1 || dist[j] < dist[u])) {
				u = j;
			}
		}
		if(u == -1) { // 如果找不到未访问过的最短距离的点，则无法构建最小生成树
			return -1;
		}
		vis[u] = ok; // 标记u已访问过
		ans += dist[u]; // 将u加入最小生成树
		for(int v = 1; v <= n; v++) {
			if(vis[v]==!ok && d[u][v] < dist[v]) { // 如果v未访问过且v到u的距离更短
				dist[v] = d[u][v]; // 更新最短距离
			}
		}
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int s, t, w;
		cin >> n >> m;
		fill(d[0], d[0] + maxn * maxn, wuqiong); // 初始化距离矩阵为无穷大
		for(int i = 0; i < m; i++) {
			cin >> s >> t >> w;
			d[s][t] = d[t][s] = w; // 边
		}
		int ans = prim(); // 求最小生成树
		cout << ans << endl;
	}
	return 0;
}
