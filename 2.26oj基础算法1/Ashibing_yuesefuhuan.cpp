#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int p[5010];
//p[i]=0,没有出列；
//p[i]=-1,人已死；
	int N;
	int n;//n为初始总人数，t为最后剩的人数
	cin>>N; 
	for (int h=0; h<N; h++) {
		cin >> n;
		memset(p, 0, sizeof(p));//把p里的数赋值为0
		int k=2;
		int cur_n = n;
		int cs;//报数的人 
		int num=0;//报的数 
		while(cur_n>3) {//超过三人 
			cs=0;
			num=0;
			while(cs<n) {
				if (p[cs] == 0) {//还站着 
					num++;//先报数，报数+1 
					if (num%k==0) {//整除2或3 
						p[cs] = -1;//倒下 
						cur_n--;//存活人数-1 
					}
				}
				cs++;//下一个人 
			}
			if(k==2) k=3;
			else k=2;
		}
		for (int i = 0; i < n; i++) {//输出
			if (p[i] ==0)cout << i+1<<" ";
		}
		cout << endl;
	}
	return 0;
}

