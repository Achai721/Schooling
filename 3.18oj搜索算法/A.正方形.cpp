#include <bits/stdc++.h>
using namespace std;
int m, n, bc;//m���� 
int a[21];
bool panduan(int now, int cnt) {
	if (now == m || cnt == m) {//����Ѿ������еı߶���������ÿ���߶���ʹ��
		if (now == m && cnt == m)//�������ͬʱ����
			return true;//����true
		else return false;//���򷵻�false
	}
	int pick[21];
	memset(pick, 0, sizeof(pick));//ûѡ�� 
	int t = bc;//�߳� 
	for (int i = now + 1; i <= m; i++) {
		if (pick[i] == 0) {//���������û���ù�������������
			pick[i] = 1;//�����������Ѿ���ʹ��
			t -= a[i];//���ڵ�t������Ҫ�Ĺ���
			if (t==0) {//�������Ҫ�ı߳�����0�������Ѿ��γ���һ����
				cnt++;//�γɵı�����1
				return panduan(i, cnt);//�ݹ�
			} else if (t < 0) { //��������ߵĳ��ȴ��ڱ߳�
				pick[i] = 0;//�������������»ָ�û���õ�״̬
				return panduan(i - 1, cnt);//�ݹ�i-1����
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
			cin >> a[i];//����ÿ��ľ���ĳ���
			sum += a[i];//sum��������ľ�����ȵĺ�
		}
		if (m < 4) {//�������С��4��һ�������γ�������
			cout << "no" << endl;//���no
			break;
		}
		if (sum % 4 != 0) {//���sum����4�ı����������������������γ�������
			cout << "no" << endl;//���no
			continue;
		}
		bc = sum / 4;//bc���Ǳ߳�
		sort(a + 1, a + m + 1);
//�����е�ľ������С�����˳������
//��a[0]��ʹ�õı������㿪ʼ�ݹ飬�������ֵ��1
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
