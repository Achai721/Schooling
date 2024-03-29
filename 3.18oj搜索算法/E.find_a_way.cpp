#include<bits/stdc++.h>
using namespace std;
const int maxn = 205;
const int INF = 0x3f3f3f3f;
char s[maxn][maxn];
int disx[] = {1,0,0,-1};
int disy[] = {0,1,-1,0};//代表右上下左四个走法
int n, m, vis[maxn][maxn], step[maxn][maxn][2];

void bfs(int x, int y, int flag) {
	memset(vis, 0, sizeof(vis));//初始化数组
	queue<pair<int,int> >q;
	map<pair<int,int>,int>mp;
	q.push({x,y});//（x，y）进入队列
	vis[x][y] = 1;//记录xy已经走过
	mp[ {x,y}] = 0; //
	while(!q.empty()) {//当队列不空的时候
		pair<int,int>t = q.front();//t就等于队首元素
		q.pop();//弹出队首元素
		if(s[t.first][t.second] == '@')//如果队首元素是KFC
			step[t.first][t.second][flag] = mp[ {t.first,t.second}]; //某个人到这的步数就是mp[{t.first,t.second}]
		for(int i = 0; i < 4; i++) {//对于四个方向进行遍历
			int fx = t.first + disx[i];
			int fy = t.second + disy[i];//更新位置
			if(fx >= 0 && fx < n && fy >= 0 && fy < m && s[fx][fy] != '#' && !vis[fx][fy]) {
				//如果没走出范围而且这个位置能走而且这个位置没走过
				vis[fx][fy] = 1;//走这个位置
				mp[ {fx,fy}] = mp[ {t.first,t.second}] + 1; //这个位置的步数++
				q.push({fx,fy});//现在的这个位置入队
			}
		}
	}
}
int main() {
	while(~scanf("%d%d", &n, &m)) {
		int yx, yy, mx, my;//第一个人的坐标和第二个人的坐标
		for(int i = 0; i < n; i++)
			scanf("%s",s[i]);//输入路况
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(s[i][j] == 'Y') {//找到Y的位置并且记录
					yx = i;
					yy = j;
				} else if(s[i][j]=='M') { //找到M的位置并且记录
					mx = i;
					my = j;
				}
			}
		}
		for (int i = 0; i < n; i++) {//把两个人到ij的时长初始化为极大值
			for (int j = 0; j < m; j++) {
				step[i][j][0] = INF;
				step[i][j][1] = INF;
			}
		}
		bfs(yx, yy, 0);//两次bfs分别计算到KFC的步数
		bfs(mx, my, 1);
		int ans = INF;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '@') {//如果是KFC
					ans = min(ans, step[i][j][0] + step[i][j][1]);
				}//答案就等于ans和两个步数的和的最小值
			}
		}
		printf("%d\n",ans*11);//输出答案
	}
	return 0;
}


