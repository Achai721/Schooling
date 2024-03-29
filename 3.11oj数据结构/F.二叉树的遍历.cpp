#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
int i;
struct Node {
	char ch;
	struct Node* left = NULL;
	struct Node* right = NULL;
};//定义一下结点
void buildTree(Node*& node, string str) { //构造二叉树
	if (i == str.length())
		return;
	if (str[i] == '#') {
		++i;//为空也不忘要++i，让i走向下一个字符
		return;
	}
	node = new Node;
	node->ch = str[i++];
	node->left = node->right = NULL;
	buildTree(node->left, str);
	buildTree(node->right, str);
}
void inOrderTraverse(Node* T) { //中序遍历
	if(T != NULL) {
		inOrderTraverse(T->left);
		cout <<T->ch << " ";
		inOrderTraverse(T->right);
	}
}
int main() {
	string str;
	Node* r;
	while (cin >> str) {
		i = 0;
		buildTree(r, str);
		inOrderTraverse(r);
		cout << endl;
	}
	return 0;
}
//typedef struct TreeNode {
//	char val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//} TNode; //先定义一下结点
//
//TNode* CreateTree(char* a,int* pi) { //先写个还原二叉树的代码，选择返回根结点的地址，留着给中序遍历用
//	if(a[*pi]=='#') {
//		++(*pi);//为空也不忘要++i，让i走向下一个字符
//		return NULL;
//	}                //#代表了空嘛，所以说明这棵树是空树
//	TNode*tree=(TNode*)malloc(sizeof(TNode));//不为空则开辟结点空间
//	if (tree==NULL) {
//		printf("malloc fall");
//		exit(-1);//开辟失败直接退出
//	}
//	tree->val=a[(*pi)];//开始给开辟好的结点开始赋值
//	++(*pi);//该变i的值，这里的i是全局变量
//	tree->left=CreateTree(a, pi);//因为题目给到的是前序遍历，所以我们还原也选择了前序
//	tree->right=CreateTree(a,pi);
//	return tree;//每次递归都会返回tree，结点地址，然后赋给left或right，最后把整棵树的根，返回给调用函数的地方
//}
//void InOder(TNode* root) { //再写个中序遍历
//	if(root==NULL) {
//		return;
//	}
//	InOder(root->left);
//	printf("%C ",root->val);
//	InOder(root->right);
//}
//int main() {
//	char str[100];
//	while(scanf("%s",str)) {
//		int i;
//		TNode* root=CreateTree(str,&i);
//		InOder(root);
//	}
//}
