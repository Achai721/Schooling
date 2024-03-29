#include<bits/stdc++.h>
#include <vector>

using namespace std;

const int maxn = 1001; // 最大节点数
vector<int> G[maxn];
bool vis[maxn]; // 标记是否访问过
bool ok = true;

void bfs(int s) {
	queue<int> q; // 定义队列
	q.push(s); // 起点入队
	vis[s] = ok; // 标记起点已访问
	while(!q.empty()) { // 当队列非空
		int u = q.front(); // 取出队首元素
		q.pop(); // 队首元素出队
		cout << u << " "; // 输出节点编号
		for(int i = 0; i < G[u].size(); i++) { // 遍历u的邻接点
			int v = G[u][i]; // 取出邻接点v
			if(vis[v]==false) { // 如果v未访问过
				q.push(v); // v入队
				vis[v] = ok; // 标记v已访问
			}
		}
	}
}

int main() {
	int n, e;
	cin >> n >> e;
	for(int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v); // 添加边
		G[v].push_back(u);
	}
	bfs(1); // 从节点1开始遍历
	cout << endl;
	return 0;
}

