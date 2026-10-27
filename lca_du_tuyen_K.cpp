#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
int n, m;
int v[MAXN], eul[2*MAXN], in[MAXN], ot[MAXN], up[17][MAXN], d[MAXN], fv[MAXN], vis[MAXN], ans;
vector<int> g[MAXN];

ll hilb(int x, int y, int p = 21, ll r = 0) {
    if (p < 0) return r;
    int h = 1 << p;
    int s = ((x & h) ? 2 : 0) | ((y & h) ? 1 : 0);
    int t[4] = {0, 3, 1, 2};
    r = r * 4 + t[s];
    int nx = x, ny = y;
    if (s == 1)      ny ^= h - 1;
    else if (s == 2) { nx ^= h - 1; ny ^= h - 1; }
    else if (s == 3) { int z = nx; nx = h - 1 - ny; ny = h - 1 - z; }
    return hilb(nx, ny, p - 1, r);
}

void dfs(int u, int p, int &T) {
    in[u] = T;
    eul[T++] = u;
    up[0][u] = p ? p : u;
    for (int w : g[u]) {
        if (w == p) continue;
        d[w] = d[u] + 1;
        dfs(w, u, T);
    }
    ot[u] = T;
    eul[T++] = u;
}

int lca(int u, int v) {
    if (d[u] > d[v]) swap(u, v);
    int diff = d[v] - d[u];
    for (int i = 0; i < 17; i++)
        if (diff >> i & 1) v = up[i][v];
    if (u == v) return u;
    for (int i = 16; i >= 0; i--) {
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}

void tog(int i) {
    int u = eul[i];
    if (vis[u]) {
        if (--fv[v[u]] == 0) ans--;
    } else {
        if (fv[v[u]]++ == 0) ans++;
    }
    vis[u] ^= 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i];

    vector<int> tmp(v + 1, v + 1 + n);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (int i = 1; i <= n; i++)
        v[i] = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();

    for (int i = 1, u, w; i < n; i++) {
        cin >> u >> w;
        g[u].push_back(w);
        g[w].push_back(u);
    }

    int T = 0;
    dfs(1, 0, T);
    for (int k = 1; k < 17; k++)
        for (int i = 1; i <= n; i++)
            up[k][i] = up[k - 1][up[k - 1][i]];

    vector<tuple<int, int, int, int>> qs;
    qs.reserve(m);
    vector<ll> ord(m);
    vector<int> res(m);
    for (int i = 0, u, w; i < m; i++) {
        cin >> u >> w;
        int z = lca(u, w), L, R;
        if (z == u || z == w) {
            L = min(in[u], in[w]);
            R = max(in[u], in[w]);
            qs.emplace_back(L, R, -1, i);
        } else {
            L = ot[u];
            R = in[w];
            qs.emplace_back(L, R, z, i);
        }
        ord[i] = hilb(L, R);
    }

    vector<int> idx(m);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return ord[a] < ord[b];
    });

    int l = 0, r = -1;
    for (int id : idx) {
        auto [L, R, lc, qi] = qs[id];
        while (l > L) tog(--l);
        while (r < R) tog(++r);
        while (l < L) tog(l++);
        while (r > R) tog(r--);
        if (lc != -1) tog(in[lc]);
        res[qi] = ans;
        if (lc != -1) tog(in[lc]);
    }

    for (int x : res)
        cout << x << "\n";
    return 0;
}
