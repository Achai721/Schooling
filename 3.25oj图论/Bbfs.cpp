#include<bits/stdc++.h>
#include <vector>

using namespace std;

const int maxn = 1001; // ���ڵ���
vector<int> G[maxn];
bool vis[maxn]; // ����Ƿ���ʹ�
bool ok = true;

void bfs(int s) {
	queue<int> q; // �������
	q.push(s); // ������
	vis[s] = ok; // �������ѷ���
	while(!q.empty()) { // �����зǿ�
		int u = q.front(); // ȡ������Ԫ��
		q.pop(); // ����Ԫ�س���
		cout << u << " "; // ����ڵ���
		for(int i = 0; i < G[u].size(); i++) { // ����u���ڽӵ�
			int v = G[u][i]; // ȡ���ڽӵ�v
			if(vis[v]==false) { // ���vδ���ʹ�
				q.push(v); // v���
				vis[v] = ok; // ���v�ѷ���
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
		G[u].push_back(v); // ��ӱ�
		G[v].push_back(u);
	}
	bfs(1); // �ӽڵ�1��ʼ����
	cout << endl;
	return 0;
}

