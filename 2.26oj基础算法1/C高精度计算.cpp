#include<iostream>
#include<vector>

using namespace std;

// C = A + B
vector<int> add(vector<int>& A, vector<int>& B) {
	vector<int> C;//定义结果数组

	int t = 0;
	for (int i = 0; i < A.size() || i < B.size(); i++) { //判断条件，是不是位数小于A或者B的长度
		if (i < A.size()) t += A[i];//把A和B的值加上
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);        //对10取模得到对应位置上的数
		t /= 10;                    //得到t是否进位
	}
	if (t) C.push_back(1);          //如果到了最后t等于1（不为0），我们就需要把t加到我们最大的位数的位置上面区 push（增加）就是加，pop（弹出）是减
	return C;                       //返回我们得到的数组
}

int main() {
	string a, b;
	vector<int> A, B;

	cin >> a >> b;                  //输入数字
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');//把字符串a和b一个一个的加入到我们的数组里面去
	for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

	int C = add(A, B);             //调用函数

	for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);//输出结果
	return 0;
}
