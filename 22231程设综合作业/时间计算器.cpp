////#include <iostream>
////#include <cmath>
////#include <>
////
////int main() {
////	long long n,y,mo,d,h,mi,s,t;
////	cin>>n;
////	for(long long i=0; i<n; i++) {
////		cin>>y>>mo>>d>>h>>mi>>s>>t;
////	}
////	t/60=mi+1 /60=h /24=d /30 31 28 29=mo /12=y
////}
//#include<iostream>
//#include<iomanip>//法二
//#include<algorithm>
//#include<cstring>
//#include<cstdio>
//using namespace std;
//void mfc_time(long long year,long long month,long long day,long long hour,long long minute,long long second,long long t) {
//	string a[13],b[32];
//	a[1]="Jan";
//	a[2]="Feb";
//	a[3]="Mar";
//	a[4]="Apr";
//	a[5]="May";
//	a[6]="Jun";
//	a[7]="Jul";
//	a[8]="Aug";
//	a[9]="Sep";
//	a[10]="Oct";
//	a[11]="Nov";
//	a[12]="Dec";
//	b[1]="1st";
//	b[2]="2nd";
//	b[3]="3rd";
//	b[4]="4th";
//	b[5]="5th";
//	b[6]="6th";
//	b[7]="7th";
//	b[8]="8th";
//	b[9]="9th";
//	b[10]="10th";
//	b[11]="11th";
//	b[12]="12th";
//	b[13]="13th";
//	b[14]="14th";
//	b[15]="15th";
//	b[16]="16th";
//	b[17]="17th";
//	b[18]="18th";
//	b[19]="19th";
//	b[20]="20th";
//	b[21]="21st";
//	b[22]="22nd";
//	b[23]="23rd";
//	b[24]="24th";
//	b[25]="25th";
//	b[26]="26th";
//	b[27]="27th";
//	b[28]="28th";
//	b[29]="29th";
//	b[30]="30th";
//	b[31]="31st";
//	second=second+t;
//	if(second>=60) {
//		minute=minute+second/60;
//		second=second%60;
//	}
//	if(minute>=60) {
//		hour=hour+minute/60;
//		minute=minute%60;
//	}
//	if(hour>=24) {
//		day=day+hour/24;
//		hour=hour%24;
//	}
//	while(month<=12) {
//		if(month==12) {
//			if(day>31) {
//				month=1;
//				day=day-31;
//				year++;
//			}
//			if(day<=31) break;
//		}
//		if(month==1||month==3||month==5||month==7||month==8||month==10) {
//			if(day>31) {
//				day=day-31;
//				month++;
//			}
//			if(day<=31) break;
//		}
//
//		if(month==2) {
//			if(year%4!=0||(year%4==0&&year%400!=0)) {
//				if(day>28) {
//					day=day-28;
//					month++;
//				}
//				if(day<=28) break;
//			} else {
//				if(day>29) {
//					day=day-29;
//					month++;
//				}
//				if(day<=29) break;
//			}
//		}
//		if(month==4||month==6||month==9||month==11) {
//			if(day>30) {
//				day=day-30;
//				month++;
//			}
//			if(day<=30) break;
//		}
//	}
//	if(hour<10) {
//		if(minute<10) {
//			if(second<10) cout<<a[month]<<" "<<b[day]<<" "<<"0"<<hour<<":"<<"0"<<minute<<":"<<"0"<<second<<" "<<year<<endl;
//			else cout<<a[month]<<" "<<b[day]<<" "<<"0"<<hour<<":"<<"0"<<minute<<":"<<second<<" "<<year<<endl;
//		}
//		if(minute>=10) {
//			if(second<10) cout<<a[month]<<" "<<b[day]<<" "<<"0"<<hour<<":"<<minute<<":"<<"0"<<second<<" "<<year<<endl;
//			else cout<<a[month]<<" "<<b[day]<<" "<<"0"<<hour<<":"<<minute<<":"<<second<<" "<<year<<endl;
//		}
//	}
//	if(hour>=10) {
//		if(minute<10) {
//			if(second<10) cout<<a[month]<<" "<<b[day]<<" "<<hour<<":"<<"0"<<minute<<":"<<"0"<<second<<" "<<year<<endl;
//			else cout<<a[month]<<" "<<b[day]<<" "<<hour<<":"<<"0"<<minute<<":"<<second<<" "<<year<<endl;
//		}
//		if(minute>=10) {
//			if(second<10) cout<<a[month]<<" "<<b[day]<<" "<<hour<<":"<<minute<<":"<<"0"<<second<<" "<<year<<endl;
//			else cout<<a[month]<<" "<<b[day]<<" "<<hour<<":"<<minute<<":"<<second<<" "<<year<<endl;
//		}
//	}
//
//}
//int main() {
//	int n;
//	cin>>n;
//	long long year,month,day,hour,minute,second,t;
//	for(int i=1; i<=n; i++) {
//		cin>>year>>month>>day>>hour>>minute>>second>>t;
//		mfc_time(year,month,day,hour,minute,second,t);
//	}
//	return 0;
//}

#include <iostream>
using namespace std;

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
    if (a == 2) { cout << "Feb";  return 0;
    }
    if (a == 3) { cout << "Mar";  return 0;
    }
    if (a == 4) { cout << "Apr";  return 0;
    }
    if (a == 5) { cout << "May";  return 0;
    }
    if (a == 6) { cout << "Jun";  return 0;
    }
    if (a == 7) { cout << "Jul";  return 0;
    }
    if (a == 8) { cout << "Aug";  return 0;
    }
    if (a == 9) { cout << "Sept";  return 0;
    }
    if (a == 10) { cout << "Oct";  return 0;
    }
    if (a == 11) { cout << "Nov";  return 0;
    }
    if (a == 12) { cout << "Dec";  return 0;
    }
    
}
int daye(int a) {
    if (a == 1||a==21||a==31) { cout <<a<< "st"; return 0;}
    if (a == 2||a==22) { cout << a << "nd"; return 0;}
    if (a == 3||a==23) { cout << a << "rd"; return 0;}
    else { cout << a << "th"; }
    return 0;
}
int runnian(int yearname) {                         //判读闰年
    if (yearname % 400 == 0 || (yearname % 4 == 0 && yearname % 100 != 0))
    {
        return 0;
    }
    return 1;
}
int main()
{
    int n;
    long long shuru[1000][7];
    int i, j;
    cin >> n;
    for (i = 0; i < n ; i++)
        for (j = 0; j < 7; j++)
            cin >> shuru[i][j];
    for (i = 0; i < n; i++) {
        long long year, month, date, hour, minute, second; long day;
        long long  f = shuru[i][6];
        year = shuru[i][0];
        month = shuru[i][1];
        date = shuru[i][2];
        second = shuru[i][5] + f % 60; f -= f % 60;if (second > 59) { second %= 60; f+=60; }
        minute = shuru[i][4] + int((f) / 60) % 60; f -= int((f) / 60) % 60; if (minute > 59) { minute %= 60; f+=3600; }
        hour = shuru[i][3] + int(f / 3600) % 24;  
        day = int(f / 86400); if (hour > 23) { hour %= 24; day++; }
        while (day > 0) {
            if (runnian(year)) {
                switch (monthc(month, date)) {
                case 0:month++, date = 1, day--; break;
                case 1:date++, day--; break;
                case 2:year++, month = 1, date = 1, day--; break;
                };
            }
            else if (!runnian(year)){
                switch (monthd(month, date)) {
                case 0:month++, date = 1, day--; break;
                case 1:date++, day--; break;
                case 2:year++, month = 1, date = 1, day--; break;
                }
            }
        }
        //循环结束 输出
        monthe(month); cout << " "; daye(date); cout << " ";
        if (hour > 10) { cout << hour << ":"; }
        else { cout << "0" << hour << ":"; }
        if (minute > 10) { cout << minute  << ":"; }
        else { cout << "0" << minute << ":"; }
        if (second > 10) { cout << second ; }
        else { cout << "0" << second; }
        cout<< " " << year << endl;
    }
}
