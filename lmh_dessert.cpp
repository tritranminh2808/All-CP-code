#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll f[100005],par[100005],vst[100005];
int x[100005],y[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
	for(int i=1;i<=100005;i++){
		f[i]=1e18;
		par[i]=-1;
	}
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	f[1]=0;
	par[1]=0;
    for(int it = 1; it <= n; it++){
        int u=-1;
        ll ub = 1e18;
        for(int i = 1; i <= n; i++){
            if(!vst[i] && f[i] < ub){
                ub =f[i];
                u = i;
            }
        }
        if(u == -1) break;
        vst[u]=1;
        // if(u == n) break;
        for(int v = 1; v <= n; v++){
            if(vst[v]) continue;
            ll w = abs(x[u] - x[v])+abs(y[u] - y[v]);
            // cout << u << " " << v  << " " << " " << f[v] << " " << w << "\n";
            ll sech= max(f[u], w);
            if(sech<f[v]){
                f[v]=sech;
                par[v] = u;
            }
        }
    }

    vector<int> path;
    for(int v = n; v != 0; v = par[v])  path.push_back(v);
    reverse(path.begin(), path.end());
	cout << f[n] << "\n";
    for(int u : path)  cout << u << " ";
    

    return 0;
}