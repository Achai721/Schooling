#include <cstdio>
#include <bits/stdc++.h>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1001;
const int maxm = 1001;
vector<int> tu[maxn]; 
bool vis[maxn]; // �������
bool ok = true;

void dfs(int x) {
	vis[x] = ok; // ��ǽڵ� x �Ѿ�������
	cout<<x<<" "; // ����ڵ� x
	for (int i = 0; i < tu[x].size(); i++) { // �����ӽڵ� x ���������б�
		int y = tu[x][i]; // ��ȡ��ǰ�ߵ��յ�
		if (vis[y]==false) { // �����յ�δ�����ʣ���Ӹ��յ㿪ʼ��������
			dfs(y);
		}
	}
}


int main() {
	int n, m;
	cin>>n>>m;
	for (int i = 1; i <= m; i++) { // �����
		int x, y;
		cin>>x>>y;
		tu[x].push_back(y);
		tu[y].push_back(x); 
	}
	dfs(1); // �ӽڵ�1��ʼ����������ȱ���
	return 0;
}
