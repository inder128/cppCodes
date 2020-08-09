// // buy/sell maximising problem

// #include <iostream> 

// using namespace std; 

// int main()
// {
// 	int n, k;
// 	cin>>n>>k;
// 	int a[n], m[k+1][n+1];
// 	for (int i = 0; i < n; ++i)
// 		cin>>a[i];
// 	for (int i = 0; i < k+1; ++i){
// 		m[i][0] = 0;
// 		m[i][1] = 0;
// 	}
// 	for (int i = 2; i < n+1; ++i)
// 		m[0][i] = 0;
// 	for (int i = 1, prev = -100000; i < k+1; ++i)
// 		for (int j = 2; j < n+1; ++j){
// 			prev = max(prev, m[i-1][j-2]-a[j-2]);
// 			m[i][j] = max(m[i][j-1], a[j-1] + prev);
// 		}
// 	cout<<m[k][n]<<endl;
//     return 0;
// }




#include <iostream>
#include <queue>
using namespace std;
struct edge {
    int v, next, c, w;
    edge() {}
    edge(int _v, int _next, int _c, int _w) {
        v = _v, next = _next, c = _c, w = _w;
    }
} e[100010];
int head[2010], tot = -1;
void addedge(int u, int v, int c, int w) {
    e[++tot] = edge(v, head[u], c, w);
    head[u] = tot;
    e[++tot] = edge(u, head[v], 0, -w);
    head[v] = tot;
}
int n, m, s, t, ansc;
long long answ;
long long dis[2010];
int last[2010], laste[2010], liu[2010];
bool inque[2010];
queue < int > q;
int spfa(int s, int t) {
    memset(dis, 63, sizeof dis);
    memset(liu, 0, sizeof liu);
    dis[s] = 0;
    inque[s] = 1;
    liu[s] = 10000000;
    q.push(s);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        inque[now] = 0;
        for (int i = head[now]; ~i; i = e[i].next) {
            if (e[i].c && e[i].w + dis[now] < dis[e[i].v]) {
                last[e[i].v] = now;
                laste[e[i].v] = i;
                liu[e[i].v] = min(liu[now], e[i].c);
                dis[e[i].v] = e[i].w + dis[now];
                if (!inque[e[i].v])
                    inque[e[i].v] = 1, q.push(e[i].v);
            }
        }
    }
    if (liu[t] == 0)
        return 0;
    for (int u = t; u != s; u = last[u]) {
        e[laste[u]].c -= liu[t];
        e[laste[u] ^ 1].c += liu[t];
    }
    ansc += liu[t];
    answ += liu[t] * dis[t];
    return 1;
}
int main() {
    memset(head, -1, sizeof head);
    int n;
    scanf("%d", &n);
    s = 0, t = n * 2 + 5;
    for (int i = 1; i <= n; i++) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        addedge(s, i, c, 0);
        addedge(i, n * 2 + 1, c, + x + y);
        addedge(i, n * 2 + 2, c, + x - y);
        addedge(i, n * 2 + 3, c, - x + y);
        addedge(i, n * 2 + 4, c, - x - y);
    }
    for (int i = 1; i <= n; i++) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        addedge(i + n, t, c, 0);
        addedge(n * 2 + 1, i + n, c, - x - y);
        addedge(n * 2 + 2, i + n, c, - x + y);
        addedge(n * 2 + 3, i + n, c, + x - y);
        addedge(n * 2 + 4, i + n, c, + x + y);
    }
    while (spfa(s, t));
    return cout << -answ << endl, 0;
}