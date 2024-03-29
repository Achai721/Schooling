#include<bits/stdc++.h>
#include<vector>
#include<queue> 
using namespace std;

const int maxn = 1001; // ��������
const int inf = 0x3f3f3f3f;

struct Edge {
	int to; // �ߵ��յ�
	int cost; // �ߵĻ���
	Edge(int t, int c) : to(t), cost(c) {} 
};

vector< Edge > tu[maxn]; // ͼ���ڽӱ�
int d[maxn]; // ��̾���
bool vis[maxn]; // ���
bool ok = true;

void dijkstra(int s) {
	fill(d + 1, d + maxn, inf); 
	fill(vis + 1, vis + maxn, !ok); 
	d[s] = 0; 
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push(make_pair(d[s], s)); // ������
	while(!q.empty()) { 
		int u = q.top().second; // ȡ���Ѷ�Ԫ�ض�Ӧ�Ľڵ���
		q.pop(); // �����Ѷ�Ԫ��
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
			tu[i].clear(); // ����ڽӱ�
		}
		for(int i = 0; i < T; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			tu[u].push_back(Edge(v, w)); // ��ӱ�
			tu[v].push_back(Edge(u, w));
		}
		for(int i = 0; i < S; i++) {
			int x;
			cin >> x;
			tu[0].push_back(Edge(x, 0)); // ��Ӳݶ��ҵ����ڳ��еıߣ�����Ϊ0
			tu[x].push_back(Edge(0, 0));
		}
		for(int i = 0; i < D; i++) {
			int x;
			cin >> x;
			tu[x].push_back(Edge(maxn - 1, 0)); // ��Ӳݶ���ȥ�ĳ��е��յ�ıߣ�����Ϊ0
			tu[maxn - 1].push_back(Edge(x, 0));
		}
		dijkstra(0); // �Ӳݶ��ҿ�ʼ�����·
		int ans = d[maxn - 1]; // �ݶ����յ�����·��Ϊ��
		if(ans == inf) { // ����޷������յ㣬�����-1
			cout << -1 << endl;
		} else {
			cout << ans << endl;
		}
	}
	return 0;
}
