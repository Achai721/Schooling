#include <cstdio>
#include <bits/stdc++.h>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1001;
const int maxm = 1001;
vector<int> tu[maxn]; 
bool vis[maxn]; // 标记数组
bool ok = true;

void dfs(int x) {
	vis[x] = ok; // 标记节点 x 已经被访问
	cout<<x<<" "; // 输出节点 x
	for (int i = 0; i < tu[x].size(); i++) { // 遍历从节点 x 出发的所有边
		int y = tu[x][i]; // 获取当前边的终点
		if (vis[y]==false) { // 若该终点未被访问，则从该终点开始继续遍历
			dfs(y);
		}
	}
}


int main() {
	int n, m;
	cin>>n>>m;
	for (int i = 1; i <= m; i++) { // 读入边
		int x, y;
		cin>>x>>y;
		tu[x].push_back(y);
		tu[y].push_back(x); 
	}
	dfs(1); // 从节点1开始进行深度优先遍历
	return 0;
}
