#include<iostream>
#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;
int s[1000];//����һ�����������ջ
char stl[10];//����һ���ַ����������ж��Ƿ�push����pop
int main() {
	int m,n,i,d,x,flag;
	scanf("%d",&m);
	getchar();//��ջ�����
	while(m--) {
		queue<int> a;//ÿһ���������ջ������
		stack<int> b;
		d=0;
		flag=0;//ÿһ�����ݽ���ʱ�� ��flag���Ϊ0
		scanf("%d",&n);
		while(n--) {
			scanf("%s",&stl);
			if(stl[1]=='u') { //��Ϊpush��pop���ַ�������ĵڶ�λ��ͬһ����uһ����o
				scanf("%d",&x);
				a.push(x);
				b.push(x);
			}
			if(stl[1]=='o') {
				if(a.empty()||b.empty())
					flag=1;//��flag����Ƿ���ջ��������Ϊ��ʱ�� ������pop
				else {
					a.pop();
					b.pop();
				}
			}
		}
		if(!flag) { //���û����������ջ������
			while(!a.empty()) {
				cout<<a.front(); //��Ϊ�������Ƚ��ȳ����Բ��������� ֱ�����
				a.pop();
				if(!a.empty())  //���������Ѿ���Ԫ������Ҫ����ո�
					cout<<" ";
			}
			cout<<endl;
			while(!b.empty()) {
				s[d]=b.top();  //��Ϊջ�Ǻ���ȳ�,�����˴������0λ�ÿ�ʼ��������
				b.pop();
				d++;
			}
			for(i=d-1; i>=0; i--) { //������Ӻ�����ǰ���
				cout<<s[i];
				if(i>0) //���������һ��Ԫ�� ������ո�
					cout<<" ";
			}
			cout<<endl;
		} else {
			cout<<"error"<<endl;  //������������error
			cout<<"error"<<endl;
		}
	}
	return 0;
}

