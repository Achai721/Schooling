#include<bits/stdc++.h>
#include<vector>
#include<queue> 
using namespace std;

const int maxn = 1001; // 最大城市数
const int inf = 0x3f3f3f3f;

struct Edge {
	int to; // 边的终点
	int cost; // 边的花费
	Edge(int t, int c) : to(t), cost(c) {} 
};

vector< Edge > tu[maxn]; // 图的邻接表
int d[maxn]; // 最短距离
bool vis[maxn]; // 标记
bool ok = true;

void dijkstra(int s) {
	fill(d + 1, d + maxn, inf); 
	fill(vis + 1, vis + maxn, !ok); 
	d[s] = 0; 
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push(make_pair(d[s], s)); // 起点入队
	while(!q.empty()) { 
		int u = q.top().second; // 取出堆顶元素对应的节点编号
		q.pop(); // 弹出堆顶元素
		if(vis[u]==ok) continue; 
		vis[u] = ok; 
		for(int i = 0; i < tu[u].size(); i++) { 
			int v = tu[u][i].to; 
			int cost = tu[u][i].cost;
			if(!vis[v] && d[v] > d[u] + cost) { 
				d[v] = d[u] + cost;
				q.push(make_pair(d[v], v)); 
			}
		}
	}
}

int main() {
	int T, S, D;
	while(cin >> T >> S >> D) {
		for(int i = 1; i <= maxn; i++) {
			tu[i].clear(); // 清空邻接表
		}
		for(int i = 0; i < T; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			tu[u].push_back(Edge(v, w)); // 添加边
			tu[v].push_back(Edge(u, w));
		}
		for(int i = 0; i < S; i++) {
			int x;
			cin >> x;
			tu[0].push_back(Edge(x, 0)); // 添加草儿家到相邻城市的边，花费为0
			tu[x].push_back(Edge(0, 0));
		}
		for(int i = 0; i < D; i++) {
			int x;
			cin >> x;
			tu[x].push_back(Edge(maxn - 1, 0)); // 添加草儿想去的城市到终点的边，花费为0
			tu[maxn - 1].push_back(Edge(x, 0));
		}
		dijkstra(0); // 从草儿家开始求最短路
		int ans = d[maxn - 1]; // 草儿到终点的最短路即为答案
		if(ans == inf) { // 如果无法到达终点，则输出-1
			cout << -1 << endl;
		} else {
			cout << ans << endl;
		}
	}
	return 0;
}
