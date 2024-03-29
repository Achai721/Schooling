//#include<iostream>
//#include<cstring>
//#include<iomanip>
//using namespace std;
////得到次数的函数
////中间变量
////int getCount(string a,string b) {
////	//子串在主串中从pos处开始最先出现的位置
////	
////	return count;
////}
//
//int main() {
//	string a,b="tju";
//	cin>>a;
//	int count=0;//次数
//	int pos=0;//检索的起始位置
//	int k=0;
//	while(k=a.find(b,pos) != -1) {
//		count++;
//		pos=k+b.length();//更新起始位置，检索位置+子串串长
//	}
//	cout<<count<<endl;
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
int occurrences_char(string str, int length, int n, char ch){
   int count = 0;
   for (int i = 0; i < length; i++){
      if (str[i] == ch){
         count++;
      }
   }
   int occ = n / length;
   count = count * occ;
   for (int i = 0; i < n % length; i++){
      if (str[i] == ch){
         count++;
      }
   }
   return count;
}
int main(){
   string str;
   cin>>str;
   char ch = 'tju';
   string s=str+str;
   int n = s.length()-1;
   int length = str.size();
   cout<<occurrences_char(str, length, n, ch);
   return 0;
}
