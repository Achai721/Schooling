////#include<bits/stdc++.h>
////using namespace std;
////const int inf=1e9;//���������
////int n,k,m,s,t,c[105],a[15][15],d[105][105],dis[105][1<<10];//c�����ʾ�����Ļ���a�����ʾ�Ļ����ϵ��d�����ʾ�������Ҽ�ľ��룬dis�����ʾ����ĳ������ʱ�Ѿ�ѧϰ���Ļ�״̬Ϊstate�����·
////struct node {
////	int u,state,dis;
////	bool operator <(const node&x)const { //����С�ںţ��������ȶ�������
////		return dis>x.dis;
////	}
////};
////void dijkstra() { //dijkstra�㷨
////	memset(dis,0x3f,sizeof(dis));//��ʼ��Ϊ�����
////	priority_queue<node>q;
////	dis[s][c[s]]=0;//����״̬Ϊ�����ҵ��Ļ�
////	q.push((node) {
////		s,c[s],0
////	});
////	while(!q.empty()) {
////		node now=q.top();
////		q.pop();
////		if(now.u==t) { //��������յ㣬ֱ�������
////			cout<<now.dis;
////			return;
////		}
////		if(now.dis>dis[now.u][now.state]) continue;//�����ǰ״̬�Ѿ����¹��ˣ�ֱ������
////		for(int i=1; i<=n; i++) { //�������й���
////			if(i==now.u) continue;//����ǵ�ǰ���ң�ֱ������
////			int new_state=now.state|c[i];//����״̬
////			if(new_state==now.state) continue;//���״̬û�иı䣬ֱ������
////			if(a[c[now.u]][c[i]]) continue;//����������ҵ��Ļ��г�ͻ��ֱ������
////			if(dis[i][new_state]>now.dis+d[now.u][i]) { //������Ը������·
////				dis[i][new_state]=now.dis+d[now.u][i];
////				q.push((node) {
////					i,new_state,dis[i][new_state]
////				});
////			}
////		}
////	}
////	cout<<"-1";//�޽�
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
////	memset(d,0x3f,sizeof(d));//��ʼ��Ϊ�����
////	for(int i=1; i<=m; i++) {
////		int u,v,w;
////		cin>>u>>v>>w;
////		d[u][v]=d[v][u]=min(d[u][v],w);//����ж�����·��ȡ��Сֵ
////	}
////	for(int k=1; k<=n; k++) { //floyd�㷨����������������·
////		for(int i=1; i<=n; i++) {
////			for(int j=1; j<=n; j++) {
////				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
////			}
////		}
////	}
////	dijkstra();//������·
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
//bool st[N][1 << K];  // st[i][j]��ʾ�Ƿ񵽹���i���㣬��ѧ�����Ļ�״̬Ϊj
//int dist[N][1 << K]; // dist[i][j]��ʾ����i���㣬ѧ�����Ļ�״̬Ϊj����̾���
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
//            if (h[u][i] != INF && !g[c[u]][c[i]]) { // ����ܵ�i�����Ҳ��ų��Ļ�
//                int ns = state | c[i];  // ����״̬
//                if (dist[i][ns] > dist[u][state] + h[u][i]) { // ������̾���
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
//    for (int i = 0; i < 1 << k; i++) // ö������ѧ�����Ļ�״̬
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


