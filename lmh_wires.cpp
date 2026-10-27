#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops,inline")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long;

static int x[3005], y_[3005], par[3005], used[3005];
static ll dist_[3005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y_[i];
        dist_[i] = LLONG_MAX;
        used[i] = 0;
        par[i]  = -1;
    }

    dist_[0] = 0;
    ll total = 0;

    for(int it = 0; it < n; it++){
        int v = -1;
        ll best = LLONG_MAX;
        for(int i = 0; i < n; i++){
            if (!used[i] && dist_[i] < best){
                best = dist_[i];
                v = i;
            }
        }
        used[v] = 1;
        total += best;

        int xv = x[v], yv = y_[v];
        for(int i = 0; i < n; i++){
            if (used[i]) continue;
            int dx = xv - x[i];
            if (dx < 0) dx = -dx;
            int dy = yv - y_[i];
            if (dy < 0) dy = -dy;
            int g = __gcd(dx, dy);
            ll w = (ll)dx + dy - g;
            if (w < dist_[i]){
                dist_[i] = w;
                par[i] = v;
            }
        }
    }

    cout << total << '\n';
    for(int i = 1; i < n; i++)  cout << par[i] + 1 << ' ' << i + 1 << '\n';
    
    return 0;
}
