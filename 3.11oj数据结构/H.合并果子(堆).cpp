#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long LL;
const int maxn=10005;
priority_queue<int,vector<int>,greater<int> >pq;
int a[maxn];
int main()
{
    int i,n,ans=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);//排序 
    for(i=0;i<n;i++)
        pq.push(a[i]);//储存到优先队列里 
    while(pq.size()>1)//不为空时 
    {
        int t1,t2;
        t1=pq.top();
        pq.pop();
        t2=pq.top();
        pq.pop();
        ans+=t1+t2;//合并求最小体力 
        pq.push(t1+t2);
    }
    printf("%d\n",ans);
    return 0;
}
