#include <bits/stdc++.h>
using namespace std;
int sz[2000005];
int par[2000005];
int find(int u){
    if(par[u]==u) return u;
    return par[u]=find(par[u]);
}
void add(int u,int v){
    u=find(u);
    v=find(v);
    if(sz[u]<sz[v]){
        par[u]=v;
        sz[v]+=sz[u];
        return;
    }
    par[v]=u;
    sz[u]+=sz[v];
}
int encode(int x, int y){
    return x*1000+y;
}
pair <int, int> decode(int x){
    return {x/1000,x%1000};
}
struct pl{
    char c; 
    int X, Y;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=2000000;i++) {
        sz[i]=1;
        par[i]=i;
    }
    while(k--){
        char c; int x,y; cin >> c >> x >>y;
        int u=encode(x,y);
        if(c=='R') {
            int v=encode(x,y+1);
            add(u,v);
        } 
        else{
            int v=encode(x+1,y);
            add(u,v);
        }
    }
    vector <pl> sol;
    int goc=find(encode(1,1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            int u = encode(i,j);
            if (j < m) {
                int v = encode(i,j+1);
                if (find(u)!=find(v)) {
                    add(u,v);
                    sol.push_back({'R',i,j});
                }
            }
            if (i<n) {
                int v = encode(i+1, j);
                if (find(u)!=find(v)) {
                    add(u,v);
                    sol.push_back({'D',i,j});
                }
            }
        }
    }
    cout << sol.size() << "\n";
    for(auto i:sol)  cout << i.c << " " << i.X << " " << i.Y << "\n";
    return 0;
}