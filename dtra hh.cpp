#include <bits/stdc++.h>
#define int long long
using namespace std;
//const int INF = 1e16;

struct pl{
	int val,id;
	bool c1,c2;
};
struct cmp{
	bool operator ()(pl &a,pl &b){
		return a.val>b.val;
	}
};
vector<pair<int, int>> adj[200005];
int kc[200005][2][2];

void dijkstra(int u) {
    kc[u][0][0]=0;
    priority_queue<pl, vector<pl>,cmp> pq;
    pq.push({0,u,0,0});
    
    while (!pq.empty()) {
        pl p = pq.top();
        pq.pop();
        
        int d=p.val,nnn=p.id;
        bool ch1=p.c1,ch2=p.c2;

        if (kc[nnn][ch1][ch2]<d) continue;
        for (auto i:adj[nnn]) {
        	int v=i.first,w=i.second;
            if (kc[v][ch1][ch2]>d+w){
                kc[v][ch1][ch2]=d+w;
                pq.push({kc[v][ch1][ch2],v,ch1,ch2});
            }
            if (!ch1&&kc[v][1][ch2]>d){
                kc[v][1][ch2]=d;
                pq.push({kc[v][1][ch2],v,1,ch2});
            }
            if (!ch2&&kc[v][ch1][1]>d+2*w){
                kc[v][ch1][1]=d+2*w;
                pq.push({kc[v][ch1][1], v, ch1, 1});
            }
            if (!ch1&&!ch2&&kc[v][1][1]>d+w){
                kc[v][1][1]=d+w;
                pq.push({kc[v][1][1],v,1,1});
            }
        }
    }
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        kc[i][0][0]=1e18;
        kc[i][1][0]=1e18;
        kc[i][0][1]=1e18;
        kc[i][1][1]=1e18;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dijkstra(1);
    for(int i=2;i<=n;i++) cout << kc[i][1][1] << " ";
    return 0;
}

