#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int p[5010];
//p[i]=0,û�г��У�
//p[i]=-1,��������
	int N;
	int n;//nΪ��ʼ��������tΪ���ʣ������
	cin>>N; 
	for (int h=0; h<N; h++) {
		cin >> n;
		memset(p, 0, sizeof(p));//��p�������ֵΪ0
		int k=2;
		int cur_n = n;
		int cs;//�������� 
		int num=0;//������ 
		while(cur_n>3) {//�������� 
			cs=0;
			num=0;
			while(cs<n) {
				if (p[cs] == 0) {//��վ�� 
					num++;//�ȱ���������+1 
					if (num%k==0) {//����2��3 
						p[cs] = -1;//���� 
						cur_n--;//�������-1 
					}
				}
				cs++;//��һ���� 
			}
			if(k==2) k=3;
			else k=2;
		}
		for (int i = 0; i < n; i++) {//���
			if (p[i] ==0)cout << i+1<<" ";
		}
		cout << endl;
	}
	return 0;
}

