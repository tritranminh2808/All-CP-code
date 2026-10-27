#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e16;


vector<pair<int, int>> adj[100005];
int kc[100005][2];

void dijkstra(int u) {
    kc[u][0] = 0;
    priority_queue<pair<int, pair<int, bool>>, vector<pair<int, pair<int, bool>>>, greater<pair<int, pair<int, bool>>>> pq;
    pq.push({0, {u, 0}});
    
    while (!pq.empty()) {
        pair<int, pair<int, bool>> p = pq.top();
        pq.pop();
        
        int dd=p.first;
        int nnn=p.second.first;
        bool uc=p.second.second;

        if (kc[nnn][uc]<dd) continue;

        for (auto i:adj[nnn]) {
            int v=i.first,c=i.second;
            if (!uc) {
                if (dd+c<kc[v][0]) {
                    kc[v][0] = dd + c;
                    pq.push({kc[v][0], {v, 0}});
                }
                if (dd+c/2<kc[v][1]) {
                    kc[v][1] = dd + c / 2;
                    pq.push({kc[v][1], {v, 1}});
                }
            } else {
                if (dd+c<kc[v][1]) {
                    kc[v][1] = dd + c;
                    pq.push({kc[v][1], {v, 1}});
                }
            }
        }
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        kc[i][0]=1e18;
        kc[i][1]=1e18;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dijkstra(1);
    cout << kc[n][1];
    return 0;
}

