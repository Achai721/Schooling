#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std ;
struct stu {    //方法一
	string name ;
	int index ;
	int chinese , math , english ;
	int total ;
	bool operator < ( stu b ) const {//重载运算符 
		if ( total != b.total ) return total < b.total ;
		else if ( chinese != b.chinese ) return chinese < b.chinese ;
		else if ( math != b.math ) return math < b.math ;
		else if ( english != b.english ) return english < b.english ;
		return index < b.index ;
	}
};
priority_queue < stu > pq ;
int main () {
	int n ;
	cin >> n ;
	while ( n -- ) {
		stu x ;
		cin >> x.index >> x.name >> x.chinese >> x.math >> x.english ;
		x.total = x.chinese + x.math + x.english ;
		pq.push ( x );
	}
	for ( int i = 0 ; i < 5 ; ++ i ) {
		cout << pq.top ( ).index << ' ';
		cout << pq.top ( ).name << ' ';
		cout << pq.top ( ).total << ' ';
		cout << endl ;
		pq.pop ( );
	}
	return 0;
}
方法二
#include<iostream>
#include<algorithm>
using namespace std;
struct student {
	int xuehao=0;
	string name;
	int chinese=0;
	int math=0;
	int english=0;
	int sum ;
} mingdan[301],temp;
bool compare(student a, student b) {
	return a.sum > b.sum;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> mingdan[i].xuehao  >> mingdan[i].name >> mingdan[i].chinese  >> mingdan[i].math >> mingdan[i].english;
		mingdan[i].sum = mingdan[i].chinese + mingdan[i].math + mingdan[i].english;
	}
	sort(mingdan+1, mingdan + 301,compare);
	for (int i = 1; i <= 5; i++) {
		if (mingdan[i].sum > mingdan[i + 1].sum)cout << mingdan[i].xuehao << " " << mingdan[i].name  << " " << mingdan[i].sum << endl;
		else {
			if (mingdan[i].chinese > mingdan[i + 1].chinese)cout << mingdan[i].xuehao << " " << mingdan[i].name  << " " << mingdan[i].sum << endl;
			else if (mingdan[i].chinese < mingdan[i + 1].chinese) {
				mingdan[i] = temp;
				mingdan[i] = mingdan[i + 1];
				mingdan[i + 1] = temp;
				cout << mingdan[i].xuehao << " " << mingdan[i].name <<  " " << mingdan[i].sum << endl;
			} else if (mingdan[i].chinese == mingdan[i + 1].chinese) {
				if (mingdan[i].math > mingdan[i + 1].math)cout << mingdan[i].xuehao << " " << mingdan[i].name << " " << mingdan[i].sum << endl;
				else if (mingdan[i].math < mingdan[i + 1].math) {
					mingdan[i] = temp;
					mingdan[i] = mingdan[i + 1];
					mingdan[i + 1] = temp;
					cout << mingdan[i].xuehao << " " << mingdan[i].name  << " " << mingdan[i].sum << endl;
				} else if (mingdan[i].math == mingdan[i + 1].math) {
					if (mingdan[i].english > mingdan[i + 1].english)cout << mingdan[i].xuehao << " " << mingdan[i].name  << " " << mingdan[i].sum << endl;
					else if (mingdan[i].english < mingdan[i + 1].english) {
						mingdan[i] = temp;
						mingdan[i] = mingdan[i + 1];
						mingdan[i + 1] = temp;
						cout << mingdan[i].xuehao << " " << mingdan[i].name  << " " << mingdan[i].sum << endl;
					} else if (mingdan[i].english == mingdan[i + 1].english) {
						if (mingdan[i].xuehao > mingdan[i + 1].xuehao)cout << mingdan[i].xuehao << " " << mingdan[i].name  << " " << mingdan[i].sum << endl;
						else if (mingdan[i].xuehao < mingdan[i + 1].xuehao) {
							mingdan[i] = temp;
							mingdan[i] = mingdan[i + 1];
							mingdan[i + 1] = temp;
							cout << mingdan[i].xuehao << " " << mingdan[i].name  << " " << mingdan[i].sum << endl;
						}
					}
				}
			}
		}
	}
	return 0;
}

