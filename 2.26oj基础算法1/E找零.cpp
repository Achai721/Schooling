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
//int moneyval[7] = { 1,2,5,10,20,50,100 };//ÿ��Ӳ�ҵ���ֵ
//int main() {
//	int T,N,c[10];
//	cin>>T;
//	for(int k=0;k<T; k++) {//ʵ��ѭ������
//		int temp;
//		int sum = 0;
//		cin >> N;
//		for(int j=0; j<=7; j++) {
//			cin>>c[j];
//		}
//		for (int i = 7; i >= 0; i--) {     //̰�Ĳ��ԣ�����ѡ����ֵ���Ʊ��
//			temp = N / moneyval[i]; //temp��¼ʹ��Ʊ��i��ö��
//			if(temp<=c[i]) {
//				N -= (temp * moneyval[i]);    //ʣ��֧�����
//				if (temp != 0)//�жϸ�����ֵ����ɹ�
//					sum+=temp;//��¼��������Ʊ������
////				cout << "�����" << temp << "��" << moneyval[i] << "���ģ�" << "ʣ���" << A << endl;
//			}
//		}
//		cout << sum << endl;//����Ʊ������
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
//����ֽ������
//�Ӵ�СѰ��
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
		if (n == 0)             //������
			cout << s << endl;
		else
			cout << "-1" << endl;
		T--;
	}
	return 0;
}
