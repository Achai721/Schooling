#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
int i;
struct Node {
	char ch;
	struct Node* left = NULL;
	struct Node* right = NULL;
};//����һ�½��
void buildTree(Node*& node, string str) { //���������
	if (i == str.length())
		return;
	if (str[i] == '#') {
		++i;//Ϊ��Ҳ����Ҫ++i����i������һ���ַ�
		return;
	}
	node = new Node;
	node->ch = str[i++];
	node->left = node->right = NULL;
	buildTree(node->left, str);
	buildTree(node->right, str);
}
void inOrderTraverse(Node* T) { //�������
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
//} TNode; //�ȶ���һ�½��
//
//TNode* CreateTree(char* a,int* pi) { //��д����ԭ�������Ĵ��룬ѡ�񷵻ظ����ĵ�ַ�����Ÿ����������
//	if(a[*pi]=='#') {
//		++(*pi);//Ϊ��Ҳ����Ҫ++i����i������һ���ַ�
//		return NULL;
//	}                //#�����˿������˵��������ǿ���
//	TNode*tree=(TNode*)malloc(sizeof(TNode));//��Ϊ���򿪱ٽ��ռ�
//	if (tree==NULL) {
//		printf("malloc fall");
//		exit(-1);//����ʧ��ֱ���˳�
//	}
//	tree->val=a[(*pi)];//��ʼ�����ٺõĽ�㿪ʼ��ֵ
//	++(*pi);//�ñ�i��ֵ�������i��ȫ�ֱ���
//	tree->left=CreateTree(a, pi);//��Ϊ��Ŀ��������ǰ��������������ǻ�ԭҲѡ����ǰ��
//	tree->right=CreateTree(a,pi);
//	return tree;//ÿ�εݹ鶼�᷵��tree������ַ��Ȼ�󸳸�left��right�������������ĸ������ظ����ú����ĵط�
//}
//void InOder(TNode* root) { //��д���������
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
