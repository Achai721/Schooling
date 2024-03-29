#include <bits/stdc++.h>//用bps写？
using namespace std;
int a[10][10], visit[10][10], b[25], c[25];
int ext[4][2] = {1,0, -1,0, 0,-1, 0,1};//代表右左下上四个方向
int mi = 99999999, flag = 0;
void dfs1(int x, int y, int step) {
	int tx, ty;//代表现在的坐标
	if(x == 4 && y == 4) {//如果已经到达出口
		if(mi > step)//如果mi没有被更新
			mi = step;//就把mi更新为step
		return ;
	}
	for (int k = 0; k < 4; k++) {//四个方向依次看是否符合条件
		tx = x + ext[k][0];//向右左下上四个方向移动
		ty = y + ext[k][1];
		if(tx < 0 || ty < 0 || tx > 4 || ty > 4)//保证还在迷宫里面
			continue;
		if (visit [tx][ty] == 0 && a[tx][ty] == 0) {//如果没走过这个位置且这个位置不是墙
			visit[tx][ty] = 1;//走这个位置
			dfs1(tx, ty, step + 1);//递归现在位置的四个方向，走过的路径++
			visit[tx][ty] = 0;//回溯，恢复到没走过这个位置的时候
		}
	}
}
void dfs2(int x, int y, int step) {
	int tx, ty;//代表现在的位置
	if(x == 4 && y == 4) { //如果到达出口
		if(step == mi && flag == 0) {//如果在dfs1里面已经走到过出口而且没输出过
			flag = 1;//代表已经输出
			for(int i = 0; i < mi; i++)//输出所有的路径
				printf("(%d, %d)\n",b[i],c[i]);
		}
		return ;
	}
	for(int k = 0; k < 4; k++) {
		tx = x + ext[k][0];//下一个位置的坐标
		ty = y + ext[k][1];
		if(tx < 0 || ty < 0 || tx > 4 || ty > 4)//保证在迷宫里面
			continue;
		if (visit[tx][ty] == 0 && a[tx][ty] == 0) {//如果没走过这个位置而且这个位置不是墙
			visit[tx][ty] = 1;//记录已经走过了这个位置
			b[step] = tx;//数组b就是记录路径中的x值
			c[step] = ty;//数组c就是记录路径中的y值
			dfs2(tx, ty, step + 1);//递归走下一步
			visit[tx][ty] = 0;//回溯，没走过这个位置
		}
	}
}
int main() {
	int i=0;
	while(i<5) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
			visit[i][j] = 0;
		}
		i++;
	}
	visit[0][0] = 1;//已经走过了00
	dfs1(0, 0, 1);//首先先走出迷宫
	dfs2(0, 0, 1);//输出路径
	return 0;
}


