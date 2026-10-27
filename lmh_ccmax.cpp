#include <bits/stdc++.h>
#define int long long
using namespace std;
struct DSU {
    vector<int> p, sz;
    vector<int> sum;
    multiset<int> S;
    DSU(int n, vector<int>& w): p(n+1), sz(n+1,1), sum(n+1) {
        iota(p.begin(), p.end(), 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = w[i];
            S.insert(sum[i]);
        }
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a,b);
        S.erase(S.find(sum[a]));
        S.erase(S.find(sum[b]));
        p[a] = b;
        sz[b] += sz[a];
        sum[b] += sum[a];
        S.insert(sum[b]);
    }
    int get_max() {
        return *prev(S.end());
    }
};
struct Op { 
    char type; int x, y; int old; 
};
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> w(n+1);
    for (int i = 1; i <= n; i++) cin >> w[i];

    vector<pair<int,int>> edge(m+1);
    for (int j = 1; j <= m; j++) cin >> edge[j].first >> edge[j].second;
    

    
    vector<Op> ops(q);
    vector<bool> del(m+1,0);

    for (int i = 0; i < q; i++) {
        char tp; cin >> tp;
        if (tp == 'D') {
            int j; cin >> j;
            ops[i] = {tp, j, 0, 0};
            del[j] = true;
        } else {
            int idx; int k;
            cin >> idx >> k;
            ops[i] = {tp, idx, (int)k, w[idx]};
            w[idx] = k;
        }
    }

    DSU dsu(n, w);
    for (int j = 1; j <= m; j++) {
        if (!del[j]) {
            dsu.unite(edge[j].first, edge[j].second);
        }
    }

    vector<int> sol(q);
    for (int i = q-1; i >= 0; i--) {
        sol[i] = dsu.get_max();
        if (ops[i].type == 'D') {
            int j = ops[i].x;
            dsu.unite(edge[j].first, edge[j].second);
        } 
        else {
            int v = ops[i].x;
            int new_w = w[v];
            int old_w = ops[i].old;
            int root = dsu.find(v);
            dsu.S.erase(dsu.S.find(dsu.sum[root]));
            dsu.sum[root] += (old_w - new_w);
            dsu.S.insert(dsu.sum[root]);
            w[v] = old_w;
        }
    }

    for (auto i: sol) cout << i << "\n";

    return 0;
}
