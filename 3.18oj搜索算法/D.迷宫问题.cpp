#include <bits/stdc++.h>//��bpsд��
using namespace std;
int a[10][10], visit[10][10], b[25], c[25];
int ext[4][2] = {1,0, -1,0, 0,-1, 0,1};//�������������ĸ�����
int mi = 99999999, flag = 0;
void dfs1(int x, int y, int step) {
	int tx, ty;//�������ڵ�����
	if(x == 4 && y == 4) {//����Ѿ��������
		if(mi > step)//���miû�б�����
			mi = step;//�Ͱ�mi����Ϊstep
		return ;
	}
	for (int k = 0; k < 4; k++) {//�ĸ��������ο��Ƿ��������
		tx = x + ext[k][0];//�����������ĸ������ƶ�
		ty = y + ext[k][1];
		if(tx < 0 || ty < 0 || tx > 4 || ty > 4)//��֤�����Թ�����
			continue;
		if (visit [tx][ty] == 0 && a[tx][ty] == 0) {//���û�߹����λ�������λ�ò���ǽ
			visit[tx][ty] = 1;//�����λ��
			dfs1(tx, ty, step + 1);//�ݹ�����λ�õ��ĸ������߹���·��++
			visit[tx][ty] = 0;//���ݣ��ָ���û�߹����λ�õ�ʱ��
		}
	}
}
void dfs2(int x, int y, int step) {
	int tx, ty;//�������ڵ�λ��
	if(x == 4 && y == 4) { //����������
		if(step == mi && flag == 0) {//�����dfs1�����Ѿ��ߵ������ڶ���û�����
			flag = 1;//�����Ѿ����
			for(int i = 0; i < mi; i++)//������е�·��
				printf("(%d, %d)\n",b[i],c[i]);
		}
		return ;
	}
	for(int k = 0; k < 4; k++) {
		tx = x + ext[k][0];//��һ��λ�õ�����
		ty = y + ext[k][1];
		if(tx < 0 || ty < 0 || tx > 4 || ty > 4)//��֤���Թ�����
			continue;
		if (visit[tx][ty] == 0 && a[tx][ty] == 0) {//���û�߹����λ�ö������λ�ò���ǽ
			visit[tx][ty] = 1;//��¼�Ѿ��߹������λ��
			b[step] = tx;//����b���Ǽ�¼·���е�xֵ
			c[step] = ty;//����c���Ǽ�¼·���е�yֵ
			dfs2(tx, ty, step + 1);//�ݹ�����һ��
			visit[tx][ty] = 0;//���ݣ�û�߹����λ��
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
	visit[0][0] = 1;//�Ѿ��߹���00
	dfs1(0, 0, 1);//�������߳��Թ�
	dfs2(0, 0, 1);//���·��
	return 0;
}


