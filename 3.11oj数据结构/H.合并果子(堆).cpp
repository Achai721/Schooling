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
    sort(a,a+n);//���� 
    for(i=0;i<n;i++)
        pq.push(a[i]);//���浽���ȶ����� 
    while(pq.size()>1)//��Ϊ��ʱ 
    {
        int t1,t2;
        t1=pq.top();
        pq.pop();
        t2=pq.top();
        pq.pop();
        ans+=t1+t2;//�ϲ�����С���� 
        pq.push(t1+t2);
    }
    printf("%d\n",ans);
    return 0;
}
