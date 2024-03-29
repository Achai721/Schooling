#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 55;
const int INF = 0x3f3f3f3f;

int n, m;
int g[MAXN][MAXN]; // �洢ͼ���ڽӾ���
int dist[MAXN][MAXN]; // �洢ÿ���㵽���������̾���

void floyd() {
	// ��ʼ��
	memcpy(dist, g, sizeof(g));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				dist[i][j] = 0;
			} else if (dist[i][j] == 0) { // ��i��jû��ֱ�ӱߣ����ʼ��ΪINF
				dist[i][j] = INF;
			}
		}
	}

	// floyd�㷨
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] != INF && dist[k][j] != INF) { // �ж��Ƿ������ת��k
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

	// ������
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

