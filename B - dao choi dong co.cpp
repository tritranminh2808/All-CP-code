#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
vector<pair<int, int>> adj[MAXN];
int dep[MAXN], dis[MAXN], par[MAXN][10];
int n, t;

void dfs(int u, int p, int d) {
    dep[u] = d;
    for (pair <int, int > pp : adj[u]) {
    	int v=pp.first,w=pp.second;
        if (v == p) continue;
        dis[v] = dis[u] + w;
        par[v][0] = u;
        dfs(v, u, d + 1);
    }
}

void build() {
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 1; i <= n; i++) {
            if (par[i][j - 1] != -1)
                par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 9; i >= 0; i--) {
        if (dep[u] - (1 << i) >= dep[v])
            u = par[u][i];
    }
    if (u == v) return u;
    for (int i = 9; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> t;
    for (int i = 1; i < n; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        adj[a].emplace_back(b, l);
        adj[b].emplace_back(a, l);
    }

    memset(par, -1, sizeof(par));
    dfs(1, -1, 0);
    build();

    while (t--) {
        int u, v;
        cin >> u >> v;
        cout << dis[u] + dis[v]-2 * dis[lca(u,v)] << "\n";
    }
}

