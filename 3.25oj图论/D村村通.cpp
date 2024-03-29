#include<bits/stdc++.h>
#include<vector>
using namespace std;

const int maxn = 1001; // ��������
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
			tu[i].clear(); // ����ڽӱ�
			vis[i] = !ok; // ��ʼ�����нڵ�Ϊδ����
		}
		for(int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			tu[u].push_back(v); // ��ӱ�
			tu[v].push_back(u);
		}
		int cnt = 0; // ��¼��ͨ����
		for(int i = 1; i <= n; i++) {
			if(vis[i]==!ok) { // ����ڵ�iδ���ʹ�
				dfs(i); // �ӽڵ�i��ʼ����
				cnt++; // ��ͨ������1
			}
		}
		cout << cnt - 1 << endl; // ��Ҫ����ĵ�·��Ϊ��ͨ������1
	}
	return 0;
}
