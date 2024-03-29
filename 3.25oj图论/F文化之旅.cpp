////#include<bits/stdc++.h>
////using namespace std;
////const int inf=1e9;//定义无穷大
////int n,k,m,s,t,c[105],a[15][15],d[105][105],dis[105][1<<10];//c数组表示国家文化，a数组表示文化间关系，d数组表示两个国家间的距离，dis数组表示到达某个国家时已经学习的文化状态为state的最短路
////struct node {
////	int u,state,dis;
////	bool operator <(const node&x)const { //重载小于号，用于优先队列排序
////		return dis>x.dis;
////	}
////};
////void dijkstra() { //dijkstra算法
////	memset(dis,0x3f,sizeof(dis));//初始化为无穷大
////	priority_queue<node>q;
////	dis[s][c[s]]=0;//起点的状态为起点国家的文化
////	q.push((node) {
////		s,c[s],0
////	});
////	while(!q.empty()) {
////		node now=q.top();
////		q.pop();
////		if(now.u==t) { //如果到达终点，直接输出答案
////			cout<<now.dis;
////			return;
////		}
////		if(now.dis>dis[now.u][now.state]) continue;//如果当前状态已经更新过了，直接跳过
////		for(int i=1; i<=n; i++) { //遍历所有国家
////			if(i==now.u) continue;//如果是当前国家，直接跳过
////			int new_state=now.state|c[i];//更新状态
////			if(new_state==now.state) continue;//如果状态没有改变，直接跳过
////			if(a[c[now.u]][c[i]]) continue;//如果两个国家的文化有冲突，直接跳过
////			if(dis[i][new_state]>now.dis+d[now.u][i]) { //如果可以更新最短路
////				dis[i][new_state]=now.dis+d[now.u][i];
////				q.push((node) {
////					i,new_state,dis[i][new_state]
////				});
////			}
////		}
////	}
////	cout<<"-1";//无解
////}
////int main() {
////	cin>>n>>k>>m>>s>>t;
////	for(int i=1; i<=n; i++) {
////		cin>>c[i];
////	}
////	for(int i=1; i<=k; i++) {
////		for(int j=1; j<=k; j++) {
////			cin>>a[i][j];
////		}
////	}
////	memset(d,0x3f,sizeof(d));//初始化为无穷大
////	for(int i=1; i<=m; i++) {
////		int u,v,w;
////		cin>>u>>v>>w;
////		d[u][v]=d[v][u]=min(d[u][v],w);//如果有多条道路，取最小值
////	}
////	for(int k=1; k<=n; k++) { //floyd算法求出任意两点间的最短路
////		for(int i=1; i<=n; i++) {
////			for(int j=1; j<=n; j++) {
////				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
////			}
////		}
////	}
////	dijkstra();//求解最短路
////	return 0;
////}
//#include <iostream>
//#include <cstring>
//#include <queue>
//using namespace std;
//
//const int N = 110, K = 10, INF = 1e9;
//int n, k, m, s, t;
//int c[N], g[K][K], h[N][N];
//bool st[N][1 << K];  // st[i][j]表示是否到过第i个点，且学过的文化状态为j
//int dist[N][1 << K]; // dist[i][j]表示到第i个点，学过的文化状态为j的最短距离
//
//struct Node {
//    int u, state, dist;
//    bool operator< (const Node& t) const {
//        return dist > t.dist;
//    }
//};
//
//void dijkstra() {
//    memset(dist, 0x3f, sizeof dist);
//    dist[s][c[s]] = 0;
//
//    priority_queue<Node> heap;
//    heap.push({s, c[s], 0});
//
//    while (heap.size()) {
//        Node t = heap.top();
//        heap.pop();
//
//        int u = t.u, state = t.state;
//        if (st[u][state]) continue;
//        st[u][state] = true;
//
//        for (int i = 1; i <= n; i++) {
//            if (h[u][i] != INF && !g[c[u]][c[i]]) { // 如果能到i，并且不排斥文化
//                int ns = state | c[i];  // 更新状态
//                if (dist[i][ns] > dist[u][state] + h[u][i]) { // 更新最短距离
//                    dist[i][ns] = dist[u][state] + h[u][i];
//                    heap.push({i, ns, dist[i][ns]});
//                }
//            }
//        }
//    }
//}
//
//int main() {
//    cin >> n >> k >> m >> s >> t;
//    for (int i = 1; i <= n; i++) cin >> c[i];
//    for (int i = 1; i <= k; i++)
//        for (int j = 1; j <= k; j++)
//            cin >> g[i][j];
//    memset(h, 0x3f, sizeof h);
//    for (int i = 0; i < m; i++) {
//        int u, v, d;
//        cin >> u >> v >> d;
//        h[u][v] = h[v][u] = min(h[u][v], d);
//    }
//
//    dijkstra();
//
//    int res = INF;
//    for (int i = 0; i < 1 << k; i++) // 枚举所有学过的文化状态
//        res = min(res, dist[t][i]);
//    if (res == INF) res = -1;
//    cout << res << endl;
//    return 0;
//}
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 101, K = 15, INF = 0x3f3f3f3f;
//
//int n, m, k, s, t;
//int culture[N];
//int g[K][K];
//int h[N][N];
//int dist[N], vis[N];
//
//void dijkstra() {
//	memset(dist, 0x3f, sizeof dist);
//	dist[s] = 0;
//	for (int i = 0; i < n; i++) {
//		int t = -1;
//		for (int j = 1; j <= n; j++) {
//			if (!vis[j] && (t == -1 || dist[j] < dist[t])) t = j;
//		}
//		vis[t] = true;
//		for (int j = 1; j <= n; j++) {
//			if (h[t][j] != INF) {
//				if (dist[j] > dist[t] + h[t][j]) dist[j] = dist[t] + h[t][j];
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> n >> k >> m >> s >> t;
//	for (int i = 1; i <= n; i++) {
//		cin >> culture[i];
//	}
//	for (int i = 1; i <= k; i++) {
//		for (int j = 1; j <= k; j++) {
//			cin >> g[i][j];
//		}
//	}
//	memset(h, 0x3f, sizeof h);
//	for (int i = 0; i < m; i++) {
//		int a, b, w;
//		cin >> a >> b >> w;
//		if (culture[a] == culture[b]) {
//			h[a][b] = h[b][a] = 0;
//		} else if (g[culture[a]][culture[b]] == 1) {
//			h[a][b] = h[b][a] = INF;
//		} else {
//			h[a][b] = h[b][a] = w;
//		}
//	}
//	dijkstra();
//	if (dist[t] == INF) cout << -1 << endl;
//	else cout << dist[t] << endl;
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
int N,K,M,S,T,d[110],cl[110];
bool f[110];
int fl[110][110];
int edge[110][110];
int main() {
    while (cin >> N >> K >> M >> S >> T) {
        memset(fl, 0, sizeof(fl));
        memset(f, 0, sizeof(f));
        memset(edge, 0x3f, sizeof(edge));
        for (int i = 1; i <= N; i++) {
            cin >> cl[i];
        }
        for (int i = 1; i <= K; i++) {
            for (int j = 1; j <= K; j++)
                cin >> fl[i][j];
        }
        for (int i = 1; i <= M; i++) {
            int u, v, d;
            cin >> u >> v >> d;
            if (fl[cl[v]][cl[u]] != 1)
                edge[u][v] = min(edge[u][v],d);
            if (fl[cl[u]][cl[v]] != 1)
                edge[v][u] = min(edge[v][u],d);
        }
        memset(d, 0x3f, sizeof(d));
        d[S] = 0;
        for (int i = 1; i <= N; i++) {
            int mi = -1;
            for (int j = 1; j <= N; j++) {
                if (!f[j] && (d[mi] > d[j] || mi == -1)) {
                    mi = j;
                }
            }
            //cout<<mi<<endl;
            f[mi] = true;
            for (int j = 1; j <= N; j++) {
                if (!f[j] && edge[mi][j] != 0 && edge[mi][j] + d[mi] < d[j]) {
                    d[j] = edge[mi][j] + d[mi];
                }
            }
        }
        if(cl[S]==cl[T]){cout<<"-1";return 0;}
        if (d[T] != 0x3f3f3f3f) {
            cout << d[T] << endl;
        } else {
            cout << "-1" << endl;
        }
    }

}


