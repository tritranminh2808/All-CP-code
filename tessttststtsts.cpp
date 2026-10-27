#include <bits/stdc++.h>
using namespace std;

struct Node { int u, d; };
struct Cmp { bool operator()(Node const &a, Node const &b) const { return a.d > b.d; } };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int f;
        cin >> f;
        vector<int> a(f+1);
        for (int i = 1; i <= f; i++) cin >> a[i];

        int k;
        cin >> k;
        vector<int> kxe(n+1, -1);
        for (int bit = 0; bit < k; bit++) {
            int idx;
            cin >> idx;             
            int v = a[idx];         
            kxe[v] = bit;           
        }

        const int INF = INT_MAX;
        vector<int> dist(n+1, INF);
        vector<vector<int>> road(n+1);
        priority_queue<Node, vector<Node>, Cmp> pq;

        dist[1] = 0;
        road[1] = {0};
        pq.push({1, 0});

        while (!pq.empty()) {
            auto [u, d] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (int v : adj[u]) {
                int nd = d + 1;
                int add = (kxe[v] >= 0 ? (1 << kxe[v]) : 0);
                
                if (nd < dist[v]) {
                    dist[v] = nd;
                    road[v].clear();
                    for (int mask : road[u]) {
                        road[v].push_back(mask | add);
                    }
                    pq.push({v, nd});
                } else if (nd == dist[v]) {
                    for (int mask : road[u]) {
                        road[v].push_back(mask | add);
                    }
                }
            }
        }

        int walkCnt = 0;
        vector<vector<char>> dp(f+1, vector<char>(1<<k, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= f; i++) {
            int v = a[i];
            auto &vec = road[v];
            sort(vec.begin(), vec.end());
            vec.erase(unique(vec.begin(), vec.end()), vec.end());

            if (kxe[v] != -1) continue;
            walkCnt++;
            for (int mask = 0; mask < (1<<k); mask++) {
                if (!dp[walkCnt-1][mask]) continue;
                for (int msk : vec) {
                    dp[walkCnt][mask | msk] = 1;
                }
            }
        }

        int best = 0;
        for (int mask = 0; mask < (1<<k); mask++)
            if (dp[walkCnt][mask])
                best = max(best, __builtin_popcount(mask));

        cout << (k - best) << '\n';
    }
    return 0;
}
