#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4.2,popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wformat-security"
using namespace std;
vector <int> adj[100005];
int par[100005];
int find(int u){
    if(par[u]<0) return u;
    return par[u]=find(par[u]);
}
void add(int u, int v){
    u=find(u);
    v=find(v);
    if(u==v) return;
    if(par[u]>par[v]) swap(u,v);
    par[v]+=par[u];
    par[u]=v;
}
bool vst[100005],dao[100005];
int color[100005];
int cnt1[100005],cnt2[100005];
int root=0;
void dfs(int u){
    vst[u]=1;
    for(auto i:adj[u]){
        if(vst[i]) continue;
        if(color[u]==1) {
            color[i]=2;
            cnt2[root]++;
        }
        else {
            color[i]=1;
            cnt1[root]++;
        }
        dfs(i);
    }
}
int f[100005];
bool sech[100005];
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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     int n,m; //cin >>n >> m
    readInt(n);
    readInt(m);
    for(int i=1;i<=n;i++)par[i]=-1;
    for(int i=1;i<=m;i++){
        int u,v; 
        readInt(u);
        readInt(v);
        add(u,v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <pair <int, int > > v;
    vector <int> list;
    list.push_back(0);
    for(int i=1;i<=n;i++){
        if(par[i]<0) {
            color[i]=1;
            root=i;
            cnt1[i]++;
            dfs(i);
            list.push_back(i);
            v.push_back({cnt1[i],cnt2[i]});
        }
    }
    int k=0;
    vector <int> a;
    a.push_back(0);
    int lim=0,ii=1;
    for(auto &i: v) {
        if(i.first>i.second) {
            swap(i.first,i.second);
            dao[ii]=1;
        }
        i.second-=i.first;
        k+=i.second;
        a.push_back(i.second);
        i.first=0;
        ii++;
    }
    lim=k;
    k/=2;
    int sz=v.size();
    for(int i=0;i<=lim;i++) f[i]=sz+1;
    f[0]=0;
    for(int i=1;i<=lim;i++){
        for(int j=1;j<=sz;j++){
            if(a[j]==0) continue;
            if(a[j]<=i&&f[i-a[j]]<j) {
                f[i]=j;
                break;
            }
        }
    }
    int minn=INT_MAX,id=-1;
    for(int i=0;i<=lim;i++){
        if(f[i]<sz+1){
            if(abs(i-k)<minn){
                minn=abs(i-k);
                id=i;
            }
        }
    }
    vector <int> sol;
    int cur=id;
    while(cur>0){
        sol.push_back(f[cur]);
        cur-=a[f[cur]];
    }
    for(auto i:sol) dao[i]=1-dao[i];
    for(int i=1;i<list.size();i++) if(dao[i]) sech[list[i]]=1;
    vector <int> room1,room2;
    for(int i=1;i<=n;i++){ 
        if(color[i]==1){
            if(sech[find(i)]) room2.push_back(i);
            else room1.push_back(i);
        }
        else{
            if(sech[find(i)]) room1.push_back(i);
            else room2.push_back(i);
        }
    }
    string out;
    // if(room1.size()>room2.size()) swap(room1,room2);
    out+=to_string(room1.size());
    out.push_back(' ');
    out+=to_string(room2.size());
    out.push_back('\n');
    // cout << room1.size() << " " << room2.size() << '\n';
    for(auto i:room1) {
        out+=to_string(i);
        out.push_back(' ');
    }
    out.push_back('\n');
    for(auto i:room2) {
        out+=to_string(i);
        out.push_back(' ');
    }
    fwrite(out.c_str(), 1, out.size(), stdout);
    return 0;
}