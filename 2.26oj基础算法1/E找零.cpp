//#include <iomNnip>
//#include<bits/stdc++.h>
//#include <cstdio>
//using namespace std;
//int main(){
//	int T,N,c[10];
//	cin>>T
//	for(int i=0;i<T;i++){
//		cin>>N;
//		for(int j=1;j<=7;j++){
//			cin>>c[j];
//		}
//
//	}
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int moneyval[7] = { 1,2,5,10,20,50,100 };//每种硬币的面值
//int main() {
//	int T,N,c[10];
//	cin>>T;
//	for(int k=0;k<T; k++) {//实现循环操作
//		int temp;
//		int sum = 0;
//		cin >> N;
//		for(int j=0; j<=7; j++) {
//			cin>>c[j];
//		}
//		for (int i = 7; i >= 0; i--) {     //贪心策略：优先选择面值大的票子
//			temp = N / moneyval[i]; //temp记录使用票子i的枚数
//			if(temp<=c[i]) {
//				N -= (temp * moneyval[i]);    //剩余支付金额
//				if (temp != 0)//判断各个面值找零成功
//					sum+=temp;//记录找零所需票子总数
////				cout << "最多找" << temp << "张" << moneyval[i] << "面额的，" << "剩余金额：" << A << endl;
//			}
//		}
//		cout << sum << endl;//最少票子总数
//	}
//	return 0;
//}
#include<iostream>
using namespace std;
int T, n, d1, d2, d5, d10, d20, d50, d100,s;
int main() {
	cin >> T;
	while (T > 0) {
		s = 0;
		cin >> n >> d1 >> d2 >> d5 >> d10 >> d20 >> d50 >> d100;
//输入纸币张数
//从大到小寻找
		while (n >= 100 && d100 > 0) {
			n -= 100;
			d100--;
			s++;
		}
		while (n >= 50 && d50 > 0) {
			n -= 50;
			d50--;
			s++;
		}
		while (n >=20 && d20 > 0) {
			n -= 20;
			d20--;
			s++;
		}
		while (n >= 10 && d10 > 0) {
			n -= 10;
			d10--;
			s++;
		}
		while (n >= 5&& d5 > 0) {
			n -= 5;
			d5--;
			s++;
		}
		while (n >= 2 && d2 > 0) {
			n -= 2;
			d2--;
			s++;
		}
		while (n >= 1 && d1 > 0) {
			n -= 1;
			d1--;
			s++;
		}
		if (n == 0)             //输出结果
			cout << s << endl;
		else
			cout << "-1" << endl;
		T--;
	}
	return 0;
}
