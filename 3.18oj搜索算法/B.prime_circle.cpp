#include<bits/stdc++.h>
using namespace std;
int n,a[25],used[25];
bool isPrime(int x){//�ж����� 
    if(x<=1){
        return false;
    }
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
void dfs(int index){
    if(index==n&&isPrime(a[0]+a[n-1])){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=2;i<=n;i++){
        if(!used[i]&&isPrime(i+a[index-1])){
            a[index]=i;//������ 
            used[i]=true;//�����߹����� 
            dfs(index+1);//�ݹ鵱ǰλ�� 
            used[i]=false;
        }
    }
}
int main(){
	long long cnt=0;
    while(cin>>n){
        memset(used,0,sizeof(used));
        a[0]=1;
        cout<<"Case "<<++cnt<<":"<<endl;
        dfs(1);
        cout<<endl;
    }
    return 0;
}
