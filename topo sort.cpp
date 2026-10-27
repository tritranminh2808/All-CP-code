#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> vis;  
vector<int> order;
int val[200005];
bool lap;
void dfs(int u) {
    vis[u]=1;
    for (int v : adj[u]) {
        if (vis[v] == 0) {
            dfs(v);
            if (lap) return;
        }
        else if (vis[v] == 1) {
            lap = true;
            return;
        }
    }
    vis[u] = 2;
    order.push_back(u);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    adj.assign(n+1, {});
    vis.assign(n+1, 0);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int u = 1; u <= n; u++){
        if(vis[u] == 0){
            dfs(u);
            if(lap){
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    reverse(order.begin(), order.end());
    for(auto i : order) cout << i << " ";
    return 0;
}

