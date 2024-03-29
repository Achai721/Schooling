#include<iostream>
#include <iomanip>
#include <cmath>
#include<algorithm>
using namespace std;
struct student {
	public:
		string name;
		double o=0;
		double t=0;
		double h=0;
		double f=0;
		double s=0;
		double sum ;
		double jq;

} md[10001];
bool compare(student a, student b) {
	return a.jq > b.jq;
}
int main() {
	int n,q,w,e,r,y;
	cin>>q>>w>>e>>r>>y;
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> md[i].name  >> md[i].o >> md[i].t  >> md[i].h >> md[i].f>>md[i].s;
		md[i].sum =(double)(md[i].o*q + md[i].t*w + md[i].h*e + md[i].f*r + md[i].s*y);
		md[i].jq = (double)(md[i].sum/(q+w+e+r+y));
	}
	sort(md+1, md + 10001,compare);
	for(int i=n-1; i>=0; i--) {                                                       //排序
		for(int j=0; j<=i; j++) {
			if(md[j+1].jq>md[j].jq) {
				swap(md[j],md[j+1]);
			} else if(md[j].jq==md[j+1].jq) {
				if(md[j+1].o>md[j].o) {
					swap(md[j],md[j+1]);
				} else if(md[j+1].o==md[j].o) {
					if(md[j+1].t>md[j].t) {
						swap(md[j],md[j+1]);
					} else if(md[j+1].t==md[j].t) {
						if(md[j+1].h>md[j].h) {
							swap(md[j],md[j+1]);
						} else if(md[j+1].h==md[j].h) {
							if(md[j].f>md[j+1].f) swap(md[j],md[j+1]);
							else if(md[j+1].f==md[j].f) {
								if(md[j+1].s>md[j].s) {
									swap(md[j],md[j+1]);
								}
							}
						}
					}

				}
			}
		}

	}
	for(int i=0; i<n; i++) {
		cout<<md[i].name<<" "<<fixed<<setprecision(2)<<md[i].jq<<endl;
	}
	return 0;
}
//	for (long long i = 0; i < n; i++) {
//		if(md[i].jq == md[i + 1].jq) {
////				if (md[i].o > md[i + 1].o)cout<<md[i].id<<" "<<fixed<<setprecision(2)<<md[i].jq<<endl;
//			if (md[i].o < md[i + 1].o) {
////				md[i] = temp;
////				md[i] = md[i + 1];
////				md[i + 1] = temp;
//				swap(md[i],md[i+1]);
////					cout << md[i].name << " "<< fixed <<setprecision(2) << md[i].jq << endl;
//			} else if (md[i].o == md[i + 1].o) {
////					if (md[i].t > md[i + 1].t)cout<<md[i].id<<" "<<fixed<<setprecision(2)<<md[i].jq<<endl;
//				if (md[i].t < md[i + 1].t) {
//					swap(md[i],md[i+1]);
////						cout << md[i].name << " " << fixed <<setprecision(2) << md[i].jq << endl;
//				} else if (md[i].t == md[i + 1].t) {
////						if (md[i].h > md[i + 1].h)cout<<md[i].id<<" "<<fixed<<setprecision(2)<<md[i].jq<<endl;
//					if (md[i].h < md[i + 1].h) {
//						swap(md[i],md[i+1]);
////							cout << md[i].name << " " << fixed <<setprecision(2) << md[i].jq << endl;
//					} else if (md[i].h == md[i + 1].h) {
////							if (md[i].f > md[i + 1].f)cout<<md[i].id<<" "<<fixed<<setprecision(2)<<md[i].jq<<endl;
//						if (md[i].f < md[i + 1].f) {
//							swap(md[i],md[i+1]);
//							//
//						} else if (md[i].f == md[i + 1].f) {
////								if (md[i].s > md[i + 1].s)cout<<md[i].id<<" "<<fixed<<setprecision(2)<<md[i].jq<<endl;
//							if (md[i].s < md[i + 1].s) {
//								swap(md[i],md[i+1]);
////									cout << md[i].name << " " << fixed <<setprecision(2) << md[i].jq << endl;
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//bool cmp2(student a, student b) { //加权比较规则
//	if (a.jq != b.jq)//总分不同
//		return a.jq >b.jq;
//	else {//相同
//		if (a.o!=b.o) return a.o>b.o;
//		else {
//			if(a.t !=b.t) return a.t>b.t;
//			else {
//				if (a.h!=b.h) return a.h>b.h;
//				else {
//					if (a.f !=b.f) return a.f>b.f;
//				}
//			}
//		}
//	}
//}
