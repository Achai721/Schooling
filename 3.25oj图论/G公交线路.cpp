#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
int n,m,s,t;
int head[maxn],tot;
struct Edge{
    int to,nxt,w;
}edge[maxn<<1];
void add(int u,int v,int w){
    edge[++tot].to=v;
    edge[tot].w=w;
    edge[tot].nxt=head[u];
    head[u]=tot;
}
int dis[maxn];
bool vis[maxn];
void dijkstra(){
    memset(dis,inf,sizeof(dis));
    memset(vis,false,sizeof(vis));
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].to;
            int w=edge[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push(make_pair(dis[v],v));
            }
        }
    }
}
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    dijkstra();
    if(dis[t]==inf) printf("-1\n"); //无解输出-1
    else printf("%d\n",dis[t]); //有解输出最短路径长度
    return 0;
}
