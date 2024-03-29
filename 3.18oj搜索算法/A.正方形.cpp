#include <bits/stdc++.h>
using namespace std;
int m, n, bc;//m根数 
int a[21];
bool panduan(int now, int cnt) {
	if (now == m || cnt == m) {//如果已经把所有的边都遍历或者每条边都被使用
		if (now == m && cnt == m)//如果两个同时符合
			return true;//返回true
		else return false;//否则返回false
	}
	int pick[21];
	memset(pick, 0, sizeof(pick));//没选过 
	int t = bc;//边长 
	for (int i = now + 1; i <= m; i++) {
		if (pick[i] == 0) {//如果这条边没被用过，就用这条边
			pick[i] = 1;//代表这条边已经被使用
			t -= a[i];//现在的t代表还需要的棍长
			if (t==0) {//如果还需要的边长等于0，代表已经形成了一条边
				cnt++;//形成的边数加1
				return panduan(i, cnt);//递归
			} else if (t < 0) { //如果这条边的长度大于边长
				pick[i] = 0;//代表这条边重新恢复没被用的状态
				return panduan(i - 1, cnt);//递归i-1条边
			}
		}
	}
	return true;
}
//void arrange(int* arr, int num) {
//	for (int i = 1; i <= num-1; i++) {
//		if (arr[i] > arr[i + 1]) {
//			int temp;
//			temp = arr[i];
//			arr[i] = arr[i + 1];
//			arr[i + 1] = temp;
//		}
//	}
////	sort(arr+1,arr+num+1) ;
//}
int main() {
	cin >> n;
	for(int ll=n; ll>0; ll--) {
		cin >> m;
		int sum = 0;
		for (int i = 1; i <= m; i++) {
			cin >> a[i];//输入每条木棒的长度
			sum += a[i];//sum就是所有木棒长度的和
		}
		if (m < 4) {//如果棒数小于4，一定不能形成正方形
			cout << "no" << endl;//输出no
			break;
		}
		if (sum % 4 != 0) {//如果sum不是4的倍数，即不能整除，不能形成正方形
			cout << "no" << endl;//输出no
			continue;
		}
		bc = sum / 4;//bc就是边长
		sort(a + 1, a + m + 1);
//把所有的木棒按从小到大的顺序排序
//从a[0]，使用的边数是零开始递归，如果返回值是1
		cout <<(panduan(0,0)?"yes":"no")<< endl;
	}
	return 0;
}

//#include<bits/stdc++.h>
//using namespace std;
//int n,a[1005],sum,side,used[1005],cnt;
//bool dfs(int index,int curr){
//
//    if(curr==side){
//        cnt++;
//        return true;
//    }
//    if(curr>side){
//        return false;
//    }
//    for(int i=index;i<n;i++){
//        if(used[i]){
//            continue;
//        }
//        used[i]=true;
//        if(dfs(i+1,curr+a[i])){
//            return true;
//        }
//        used[i]=false;
//    }
//    return false;
//}
//int ccnt;
//bool canFormSquare(){
//    if(n<4){
//        return false;
//    }
//    sum=0;
//    for(int i=0;i<n;i++){
//        sum+=a[i];
//    }
//    if(sum%4!=0){
//        return false;
//    }
//    side=sum/4;
//    memset(used,0,sizeof(used));
//    ccnt=0;
//    dfs(0,0);
//    return ccnt==4;
//}
//int main(){
//    int t;
//    cin>>t;
//    while(t--){
//        cin>>n;
//        for(int i=0;i<n;i++){
//            cin>>a[i];
//        }
//        cout<<(canFormSquare()?"yes":"no")<<endl;
//    }
//    return 0;
//}
