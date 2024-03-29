#include<iostream>
#include<vector>

using namespace std;

// C = A + B
vector<int> add(vector<int>& A, vector<int>& B) {
	vector<int> C;//����������

	int t = 0;
	for (int i = 0; i < A.size() || i < B.size(); i++) { //�ж��������ǲ���λ��С��A����B�ĳ���
		if (i < A.size()) t += A[i];//��A��B��ֵ����
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);        //��10ȡģ�õ���Ӧλ���ϵ���
		t /= 10;                    //�õ�t�Ƿ��λ
	}
	if (t) C.push_back(1);          //����������t����1����Ϊ0�������Ǿ���Ҫ��t�ӵ���������λ����λ�������� push�����ӣ����Ǽӣ�pop���������Ǽ�
	return C;                       //�������ǵõ�������
}

int main() {
	string a, b;
	vector<int> A, B;

	cin >> a >> b;                  //��������
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');//���ַ���a��bһ��һ���ļ��뵽���ǵ���������ȥ
	for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

	int C = add(A, B);             //���ú���

	for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);//������
	return 0;
}
