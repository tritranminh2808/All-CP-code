#include <bits/stdc++.h>
using namespace std;
vector <int> adj[200005];
int sz[200005];
bool vst[200005];
int k1,k2,n;
static const int IN_BUF = 1<<20;
static char ibuf[IN_BUF];
static int ipos = 0, ilen = 0;
inline int readChar() {
    if (ipos >= ilen) {
        ilen = (int)fread(ibuf,1,IN_BUF,stdin);
        ipos = 0;
        if (ilen == 0) return EOF;
    }
    return ibuf[ipos++];
}
template<typename T>
bool readInt(T &out) {
    int c;
    do {
        c = readChar();
        if (c == EOF) return false;
    } while (c!='-' && (c<'0' || c>'9'));
    int sign = 1;
    if (c == '-') {
        sign = -1;
        c = readChar();
    }
    long long val = 0;
    while (c >= '0' && c <= '9') {
        val = val*10 + (c - '0');
        c = readChar();
    }
    out = (T)(val * sign);
    return true;
}
string out;
void dfs(int u, int v){
    sz[u]=1;
    for(auto i:adj[u]){
        if(vst[i]||i==v) continue;
        dfs(i,u);
        sz[u]+=sz[i];
    }
}
long long res[200005];
int centroid(int u, int v, int x){
    for(auto i:adj[u]){
        if(vst[i]||i==v) continue;
        if(sz[i]>x/2) return centroid(i,u,x);
    }
    return u;
}
// int maxx=0;
int dep[200005];
long long s=0,cnt=0;
void lay(int u, int v){
    s+=dep[u];
    cnt++;
    for(auto i:adj[u]){
        if(i==v||vst[i]) continue;
        dep[i]=dep[u]+1;
        lay(i,u);
    }
}
void xoa(int u, int v){
    s-=dep[u];
    cnt--;
    for(auto i: adj[u]){
        if(i==v||vst[i]) continue;
        dep[i]=dep[u]+1;
        xoa(i,u);
    }
}
void cal(int u, int v){
    res[u]+=s+dep[u]*cnt;
    for(auto i:adj[u]){
        if(i==v||vst[i]) continue;
        dep[i]=dep[u]+1;
        cal(i,u);
    }
}

void centroi(int u, int v){
    dfs(u,0);
    int x=sz[u];
    int tam=centroid(u,0,x);
    dep[tam]=0;
    vst[tam]=1;
    cnt=1;
    s=0;
    for(auto i:adj[tam]){
        if(vst[i]) continue;
        dep[i]=1;
        lay(i,tam);   
    }
    res[tam]+=s;
    for(auto i:adj[tam]){
        if(vst[i]) continue;
        dep[i]=1;
        xoa(i,tam);  
        dep[i]=1;
        cal(i,tam);
        dep[i]=1;
        lay(i,tam); 
    }
    // for(int pos:lit) update(pos, -1);
// lit.clear();
    for(auto i:adj[tam]) if(!vst[i]) centroi(i,tam);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cin >> n >> k;
    readInt(n);
    
    for(int i=1;i<n;i++){
        int u,v;// cin >> u >> v;
        readInt(u);
        readInt(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // txl(1,0);
    centroi(1,0);
    for(int i=1;i<=n;i++) {
        out+=to_string(res[i]);
        out+=" ";
    }
    fwrite(out.c_str(), 1, out.size(), stdout);
    // cout << res;
    return 0;
}
