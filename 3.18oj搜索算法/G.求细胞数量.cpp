#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 205;  // �������С

int n, m, cnt;  // cnt��ʾϸ������
int dx[4] = {-1, 0, 1, 0};  // �ĸ�����
int dy[4] = {0, 1, 0, -1};
bool visited[MAXN][MAXN];  // �������
char matrix[MAXN][MAXN];  // �洢����

void dfs(int x, int y) {
	visited[x][y] = true;  // ���Ϊ�ѷ���
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] != '0' && !visited[nx][ny]) {
			dfs(nx, ny);  // �Ӹ�ϸ����ʼ�����������
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> matrix[i];
	}
	memset(visited, false, sizeof(visited));  // ��ʼ��Ϊδ����
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] != '0' && !visited[i][j]) {  // δ���ʵ�ϸ��
				cnt++;
				dfs(i, j);  // �Ӹ�ϸ����ʼ�����������
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
