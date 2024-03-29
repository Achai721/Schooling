#include<bits/stdc++.h>
#include <vector>
using namespace std;

const int maxn = 105; 
// ����۹���
const int wuqiong = 0x3f3f3f3f; 
// ��������� 

int n, m; // �۹����ͱ���
int d[maxn][maxn]; // �������
int dist[maxn]; // ��̾�������
bool vis[maxn]; // �������
bool ok = 1;

int prim() {
	fill(dist + 1, dist + n + 1, wuqiong); // ��ʼ����̾��������
	fill(vis + 1, vis + n + 1, !ok); // ��ʼ�����е�Ϊδ����
	dist[1] = 0; // ��1���۹޿�ʼ������С������
	int ans = 0; // Ȩֵ
	for(int i = 1; i <= n; i++) { // ����n���ڵ����С������
		int u = -1; // u��ʾδ���ʹ�����̾���ĵ�
		for(int j = 1; j <= n; j++) { // �������е��ҵ�δ���ʹ�����̾���ĵ�
			if(vis[j]==!ok && (u == -1 || dist[j] < dist[u])) {
				u = j;
			}
		}
		if(u == -1) { // ����Ҳ���δ���ʹ�����̾���ĵ㣬���޷�������С������
			return -1;
		}
		vis[u] = ok; // ���u�ѷ��ʹ�
		ans += dist[u]; // ��u������С������
		for(int v = 1; v <= n; v++) {
			if(vis[v]==!ok && d[u][v] < dist[v]) { // ���vδ���ʹ���v��u�ľ������
				dist[v] = d[u][v]; // ������̾���
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
		fill(d[0], d[0] + maxn * maxn, wuqiong); // ��ʼ���������Ϊ�����
		for(int i = 0; i < m; i++) {
			cin >> s >> t >> w;
			d[s][t] = d[t][s] = w; // ��
		}
		int ans = prim(); // ����С������
		cout << ans << endl;
	}
	return 0;
}
