#include <bits/stdc++.h>
using namespace std;
vector <int> adj[200005];
int sz[2000005];
bool vst[200005];
// int depg[200005];
int d;
int cnt=1;
int f[200005];// khoang cach den thang gan nhat trong nhanh u chon duoc
int dis=0;
void dfs(int u, int v){
    f[u]=0;
    for(auto i:adj[u]){
        if(i==v) continue;
        dfs(i,u);
        int dist=f[i]+1;
        if(dist+f[u]>=d) {
            cnt++;
            f[u]=min(f[u],dist);
        }
        else f[u]=max(f[u],dist);
    }
    // dis--;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n >> d;
    for(int i=1;i<n;i++){
        int u; cin>> u; 
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    dfs(0,-1);
    cout << cnt;
    return 0;
}