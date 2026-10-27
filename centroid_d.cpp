#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct pl{
    int to, w;
};
vector <pl> adj[200005];
int sz[2000005];
bool vst[200005];
// int depg[200005];
int k;
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
// string out;
int g[100005];
void dfs(int u, int v){
    sz[u]=1;
    for(auto i:adj[u]){
        if(vst[i.to]||i.to==v) continue;
        dfs(i.to,u);
        sz[u]+=sz[i.to];
    }
}
long long res=0;
int centroid(int u, int v, int x){
    for(auto i:adj[u]){
        if(vst[i.to]||i.to==v) continue;
        if(sz[i.to]>x/2) return centroid(i.to,u,x);
    }
    return u;
}
ll fuel[200005];
int cnt[200005],dep[200005];
vector<int> lit;
int ans=0;
struct Info{ ll P, minPref, maxBefore; int node; };

void collect(int start,int p,int from_len, vector<Info> &out){
    struct St{int u,p; ll P,minPref,maxBefore;};
    vector<St> st;
    ll initP = fuel[start] - from_len;              
    st.push_back({start, p, initP, min(initP, 0LL), 0LL});
    while(!st.empty()){
        auto cur = st.back(); st.pop_back();
        out.push_back({cur.P, cur.minPref, cur.maxBefore, cur.u});
        for(auto &e: adj[cur.u]){
            if(e.to==cur.p || vst[e.to]) continue;
            ll Pn = cur.P + (fuel[e.to] - e.w);
            st.push_back({e.to, cur.u, Pn, min(cur.minPref, Pn), max(cur.maxBefore, cur.P)});
        }
    }
}
void run(int c){
    vector<ll> allM;
    vector<vector<ll>> childM;
    vector<vector<ll>> childR;

    for(auto &e: adj[c]) if(!vst[e.to]){
        vector<Info> v; collect(e.to, c, e.w, v);
        vector<ll> mins; mins.reserve(v.size());
        vector<ll> Rs;   Rs.reserve(v.size());
        for(auto &it: v){
            mins.push_back(it.minPref);
            if(fuel[it.node] + it.P >= it.maxBefore) Rs.push_back(fuel[it.node] + it.P);
        }
        sort(mins.begin(), mins.end());
        allM.insert(allM.end(), mins.begin(), mins.end());
        childM.push_back(move(mins));
        childR.push_back(move(Rs));
    }

    sort(allM.begin(), allM.end());

    for(size_t i=0;i<childR.size();++i){
        for(ll R: childR[i]){
            ll need = -R;
            ll tot = (ll)(allM.end() - lower_bound(allM.begin(), allM.end(), need));
            ll same = (ll)(childM[i].end() - lower_bound(childM[i].begin(), childM[i].end(), need));
            ans += (tot - same);
        }
    }

    if(!allM.empty()){
        ll need = -fuel[c];
        ans += (ll)(allM.end() - lower_bound(allM.begin(), allM.end(), need));
    }
    if(fuel[c] >= 0) ++ans;
}

void centroi(int u, int v){
    dfs(u,0);
    int x=sz[u];
    int tam=centroid(u,0,x);
    // dep[tam]=0;
    run(tam);
    vst[tam]=1;
    for(auto i:adj[tam]) if(!vst[i.to]) centroi(i.to,tam);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; //cin >> n >> k;
    readInt(n);
    for(int i=1;i<=n;i++) readInt(fuel[i]);
    for(int i=1;i<n;i++){
        int u,v,w;// cin >> u >> v;
        readInt(u);
        readInt(v);
        readInt(w);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    // txl(1,0);
    centroi(1,0);
    
    cout << ans;
    return 0;
}