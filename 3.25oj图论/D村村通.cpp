#include<bits/stdc++.h>
#include<vector>
using namespace std;

const int maxn = 1001; // 最大城镇数
vector<int> tu[maxn]; 
bool vis[maxn]; 
bool ok = true;

void dfs(int u) {
	vis[u] = ok; 
	for(int i = 0; i < tu[u].size(); i++) { 
		int v = tu[u][i]; 
		if(vis[v]==!ok) { 
			dfs(v); 
		}
	}
}

int main() {
	int n, m;
	while(cin >> n >> m) {
		for(int i = 1; i <= n; i++) {
			tu[i].clear(); // 清空邻接表
			vis[i] = !ok; // 初始化所有节点为未访问
		}
		for(int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			tu[u].push_back(v); // 添加边
			tu[v].push_back(u);
		}
		int cnt = 0; // 记录连通块数
		for(int i = 1; i <= n; i++) {
			if(vis[i]==!ok) { // 如果节点i未访问过
				dfs(i); // 从节点i开始遍历
				cnt++; // 连通块数加1
			}
		}
		cout << cnt - 1 << endl; // 需要建设的道路数为连通块数减1
	}
	return 0;
}
