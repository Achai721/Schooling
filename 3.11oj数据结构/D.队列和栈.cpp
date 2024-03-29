#include<iostream>
#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;
int s[1000];//定义一个数组来存放栈
char stl[10];//定义一个字符串数组来判断是否push或者pop
int main() {
	int m,n,i,d,x,flag;
	scanf("%d",&m);
	getchar();//清空缓冲区
	while(m--) {
		queue<int> a;//每一组进来重置栈和数列
		stack<int> b;
		d=0;
		flag=0;//每一组数据进来时候 将flag标记为0
		scanf("%d",&n);
		while(n--) {
			scanf("%s",&stl);
			if(stl[1]=='u') { //因为push和pop的字符串数组的第二位不同一个是u一个是o
				scanf("%d",&x);
				a.push(x);
				b.push(x);
			}
			if(stl[1]=='o') {
				if(a.empty()||b.empty())
					flag=1;//用flag标记是否在栈或者数列为空时候 还输入pop
				else {
					a.pop();
					b.pop();
				}
			}
		}
		if(!flag) { //如果没被标记则输出栈和数列
			while(!a.empty()) {
				cout<<a.front(); //因为队列是先进先出所以不用数组存放 直接输出
				a.pop();
				if(!a.empty())  //若队列中已经无元素则不需要输出空格
					cout<<" ";
			}
			cout<<endl;
			while(!b.empty()) {
				s[d]=b.top();  //因为栈是后进先出,将顶端从数组的0位置开始用数组存放
				b.pop();
				d++;
			}
			for(i=d-1; i>=0; i--) { //让数组从后面往前输出
				cout<<s[i];
				if(i>0) //若不是最后一个元素 则输出空格
					cout<<" ";
			}
			cout<<endl;
		} else {
			cout<<"error"<<endl;  //若被标记则输出error
			cout<<"error"<<endl;
		}
	}
	return 0;
}

