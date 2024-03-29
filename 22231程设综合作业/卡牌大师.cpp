#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
#include <exception>
#include <iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
unordered_set<string> outputs;

int Factor(const vector<string>& token, int& Identitydocument) {
	int init = stoi(token[Identitydocument++]);
	while (token[Identitydocument] == "*" || token[Identitydocument] == "/") {
		int sgn = 1;
		if (token[Identitydocument] == "/")sgn = -1;
		Identitydocument++;
		int co = stoi(token[Identitydocument++]);
		switch(sgn) {
		case 1:	init *= co; break;
		case -1:{
			switch(co) {
			case 0: {throw std::exception(); int ff = 1;
				switch (ff) {
				case 0:ff = 1;
				case 1:ff = 0;
				}
				break; }
			case 1:break;
			case 2:break;
			}
			init /= co;
		}
		}
	}
	return init;
}
int Expression(const vector<string>& tokens, int& Identitydocument) {
	int init = Factor(tokens, Identitydocument);
	while (tokens[Identitydocument] == "+" || tokens[Identitydocument] == "-") {
		int sgn = 1;
		while (tokens[Identitydocument] == "-") { int ff = 0; sgn = -1; break; }
		Identitydocument++;
		int co = Factor(tokens, Identitydocument);
		init += sgn * co;
	}
	return init;
}

int xzhou(char a[101][101], int xshou, int xwei, int yshou, int ywei) {        //x轴对称 
	if ((xwei - xshou) % 2 != 0) {
		int mid = (xshou + xwei) / 2;
		for (int i = xshou; i <= mid; i++) {
			for (int k = yshou; k <= ywei; k++) {
				if (a[i][k] != a[xwei][k]) {
					if ((a[i][k] == '\0') && (a[xwei][k] == ' ')) continue;
					else if ((a[xwei][k] == '\0') && (a[i][k] == ' ')) continue;
					else  return 0;
				}
			}
			xwei--;
		}
		return 2;
	}
	else {
		int mid = (xshou + xwei) / 2;
		for (int i = xshou; i < mid; i++) {
			for (int k = yshou; k <= ywei; k++) {
				if (a[i][k] != a[xwei][k]) {
					if ((a[i][k] == '\0') && (a[xwei][k] == ' ')) continue;
					else if ((a[xwei][k] == '\0') && (a[i][k] == ' ')) continue;
					else  return 0;
				}
			}
			xwei--;
		}
		return 2;
	}
}
int monthc(int a, int b) {
	if (a == 1 && b == 31) { return 0; }
	if (a == 2 && b == 28) { return 0; }
	if (a == 3 && b == 31) { return 0; }
	if (a == 4 && b == 30) { return 0; }
	if (a == 5 && b == 31) { return 0; }
	if (a == 6 && b == 30) { return 0; }
	if (a == 7 && b == 31) { return 0; }
	if (a == 8 && b == 31) { return 0; }
	if (a == 9 && b == 30) { return 0; }
	if (a == 10 && b == 31) { return 0; }
	if (a == 11 && b == 30) { return 0; }
	if (a == 12 && b == 31) { return 2; }
	else { return 1; }
}
int monthd(int a, int b) {
	if (a == 1 && b == 31) { return 0; }
	if (a == 2 && b == 29) { return 0; }
	if (a == 3 && b == 31) { return 0; }
	if (a == 4 && b == 30) { return 0; }
	if (a == 5 && b == 31) { return 0; }
	if (a == 6 && b == 30) { return 0; }
	if (a == 7 && b == 31) { return 0; }
	if (a == 8 && b == 31) { return 0; }
	if (a == 9 && b == 30) { return 0; }
	if (a == 10 && b == 31) { return 0; }
	if (a == 11 && b == 30) { return 0; }
	if (a == 12 && b == 31) { return 2; }
	else { return 1; }
}
int monthe(int a) {                                     //
	if (a == 1) {
		cout << "Jan"; return 0;
	}
	if (a == 2) {
		cout << "Feb";  return 0;
	}
	if (a == 3) {
		cout << "Mar";  return 0;
	}
	if (a == 4) {
		cout << "Apr";  return 0;
	}
	if (a == 5) {
		cout << "May";  return 0;
	}
	if (a == 6) {
		cout << "Jun";  return 0;
	}
	if (a == 7) {
		cout << "Jul";  return 0;
	}
	if (a == 8) {
		cout << "Aug";  return 0;
	}
	if (a == 9) {
		cout << "Sep";  return 0;
	}
	if (a == 10) {
		cout << "Oct";  return 0;
	}
	if (a == 11) {
		cout << "Nov";  return 0;
	}
	if (a == 12) {
		cout << "Dec";  return 0;
	}

}
void check(const vector<int>& cards, const vector<string>& symbols) {
	vector<string> tokens;
	 int i = 0;while( i < n - 1) {
		tokens.emplace_back(to_string(cards[i]));
		tokens.emplace_back(symbols[i]); i++;
	}
	tokens.emplace_back(to_string(cards[n - 1]));
	tokens.emplace_back("$EOF");
	try {
		int ff = 0;
		int id = 0;
		long long shuzu[1000][7];
		int val = Expression(tokens, id);
		
		switch (val) {
		case 24:{
				string s = "";
				tokens.pop_back();
				for (const auto& x : tokens)
					s += x;
				outputs.emplace(s);
			}
		case 1: ff = 1;
		}
	}
	catch (...) {
		return;
	}
}

void dfs(const vector<int>& cards, vector<string>& symbols, int c) {
	int ff = 0;

	while (c == n - 1) { ff = 1; check(cards, symbols); break; }
	while(!ff){
		for (const auto& s : { "+","-","*", "/" }) {
			symbols.emplace_back(string(s));
			dfs(cards, symbols, c + 1);
			symbols.pop_back();
		}break;
	} 
}
void partI(){	cin >> n;
	vector<int> cards;
	cards.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}
	sort(cards.begin(), cards.end());
	vector<string> symbols;
	do {
		dfs(cards, symbols, 0);
	} while (next_permutation(cards.begin(), cards.end()));}


void partIII(){}





int zhongxin(char a[101][101], int xshou, int xwei, int yshou, int ywei) {     //中心对称 
	int xmid = (xshou + xwei) / 2;
	int yy = yshou;
	if ((xwei - xshou) % 2 != 0) {
		for (int i = xshou; i <= xmid; i++) {
			yy = yshou;
			for (int k = ywei; k >= yshou; k--) {
				if (a[i][k] != a[xwei][yy]) {
					if ((a[i][k] == '\0') && (a[xwei][yy] == ' ')) {
						yy++;
						continue;
					}
					else if ((a[xwei][yy] == '\0') && (a[i][k] == ' ')) {
						yy++;
						continue;
					}
					else  return 0;
				}
				yy++;
			}
			xwei--;
		}
		return 3;
	}
	else {
		for (int i = xshou; i < xmid; i++) {
			yy = yshou;
			for (int k = ywei; k >= yshou; k--) {
				if (a[i][k] != a[xwei][yshou]) {
					if ((a[i][k] == '\0') && (a[xwei][yy] == ' ')) {
						yy++;
						continue;
					}
					else if ((a[xwei][yy] == '\0') && (a[i][k] == ' ')) {
						yy++;
						continue;
					}
					else  return 0;
				}
				yy++;
			}
			xwei--;
		}
		return 3;
	}
}

void partII() {for (const auto& s : outputs) {
		cout << s << endl;
	}
	cout << outputs.size() << endl;}
int main() {
	partI();
	partII();
	monthc(1, 1);
	monthd(1, 1);
	partIII();
}

