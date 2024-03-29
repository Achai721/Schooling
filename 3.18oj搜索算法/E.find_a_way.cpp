#include<bits/stdc++.h>
using namespace std;
const int maxn = 205;
const int INF = 0x3f3f3f3f;
char s[maxn][maxn];
int disx[] = {1,0,0,-1};
int disy[] = {0,1,-1,0};//�������������ĸ��߷�
int n, m, vis[maxn][maxn], step[maxn][maxn][2];

void bfs(int x, int y, int flag) {
	memset(vis, 0, sizeof(vis));//��ʼ������
	queue<pair<int,int> >q;
	map<pair<int,int>,int>mp;
	q.push({x,y});//��x��y���������
	vis[x][y] = 1;//��¼xy�Ѿ��߹�
	mp[ {x,y}] = 0; //
	while(!q.empty()) {//�����в��յ�ʱ��
		pair<int,int>t = q.front();//t�͵��ڶ���Ԫ��
		q.pop();//��������Ԫ��
		if(s[t.first][t.second] == '@')//�������Ԫ����KFC
			step[t.first][t.second][flag] = mp[ {t.first,t.second}]; //ĳ���˵���Ĳ�������mp[{t.first,t.second}]
		for(int i = 0; i < 4; i++) {//�����ĸ�������б���
			int fx = t.first + disx[i];
			int fy = t.second + disy[i];//����λ��
			if(fx >= 0 && fx < n && fy >= 0 && fy < m && s[fx][fy] != '#' && !vis[fx][fy]) {
				//���û�߳���Χ�������λ�����߶������λ��û�߹�
				vis[fx][fy] = 1;//�����λ��
				mp[ {fx,fy}] = mp[ {t.first,t.second}] + 1; //���λ�õĲ���++
				q.push({fx,fy});//���ڵ����λ�����
			}
		}
	}
}
int main() {
	while(~scanf("%d%d", &n, &m)) {
		int yx, yy, mx, my;//��һ���˵�����͵ڶ����˵�����
		for(int i = 0; i < n; i++)
			scanf("%s",s[i]);//����·��
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(s[i][j] == 'Y') {//�ҵ�Y��λ�ò��Ҽ�¼
					yx = i;
					yy = j;
				} else if(s[i][j]=='M') { //�ҵ�M��λ�ò��Ҽ�¼
					mx = i;
					my = j;
				}
			}
		}
		for (int i = 0; i < n; i++) {//�������˵�ij��ʱ����ʼ��Ϊ����ֵ
			for (int j = 0; j < m; j++) {
				step[i][j][0] = INF;
				step[i][j][1] = INF;
			}
		}
		bfs(yx, yy, 0);//����bfs�ֱ���㵽KFC�Ĳ���
		bfs(mx, my, 1);
		int ans = INF;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '@') {//�����KFC
					ans = min(ans, step[i][j][0] + step[i][j][1]);
				}//�𰸾͵���ans�����������ĺ͵���Сֵ
			}
		}
		printf("%d\n",ans*11);//�����
	}
	return 0;
}


