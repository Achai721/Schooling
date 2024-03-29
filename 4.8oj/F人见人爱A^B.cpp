/*
题目描述
求A^B的最后三位数表示的整数。
说明：A^B的含义是“A的B次方”
输入
输入数据包含多个测试实例，每个实例占一行，由两个正整数A和B组成（1<=A,B<=10000），如果A=0, B=0，则表示输入数据的结束，不做处理。
输出
对于每个测试实例，请输出A^B的最后三位表示的整数，每个输出占一行。
*/
#include<bits/stdc++.h>
using namespace std;
long long a,b;
int main() {
	while(cin>>a>>b) { //a或b为0时结束
		if(a!=0&&b!=0) {
			long long ans=1;
			for(long long i=1; i<=b; i++) { //循环b次
				ans*=a;//计算a的b次方
				ans%=1000;//取最后三位数
			}
			cout<<ans<<endl;//输出
		} else {
			break;
		}
	}
	return 0;
}
