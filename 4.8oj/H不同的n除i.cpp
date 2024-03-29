/*
题目描述
给定一个n，对于i从1到n，找出有多少个不同的n/i
如：n=6
有4个不同的n/i：6，3，2，1
输入
第一行一个T，表示有T组数据(T < 100000)
之后T行，每行一个n(n <= 10^18)
输出
每行输出一个数，表示不同的个数
*/
#include<bits/stdc++.h>
using namespace std;
long long m,n;
int main() {
	cin>>n;
	while(n--) {
		cin>>m;
		long long pou=sqrt(m+1);
		for(long long i=pou; i<=m; i++) {
			long long jian=i*(i-1);
			long long jia=i*(i+1);//判断第几行 
			if(m+1>jian&&m+1<=jia) {  //判断前半段后半段 
				if(m+1-jian<=i) {
					cout<<2*i-2<<endl;
				} else {
					cout<<2*i-1<<endl;
				}
				break;
			}
		}
	}
}
//0 0
//1 1           2 4 6 
//23 2
//45 3
//678 4
//91011 5  
