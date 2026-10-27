#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4.2,popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wformat-security"
// #define int long long
using namespace std;
using ll=long long;
int n,m,T;
int a[705][705];
int b[705][705];
ll sz[1000005],par[1000005];
struct pl{
    int u,v;
    long double w;
};
pair <ll,ll > pluss(ll a, ll ts, ll ms){
    ll t=a*ms+ts,m=ms;
    ll g=__gcd(t,m);
    t/=g;
    m/=g;
    return {t,g};
}
const int base=257,mod=1e9+7;
ll hasht(ll a, ll b, ll c, ll d){           
    ll h=a;
    h=h*base+ b;
    h=h*base+c;
    h=h*base+ d;
    return h;
}
ll encode(int x,int y){
    return x*700+y;
}
pair <int, int > decode(int x){
    return {x/700,x%700};
}
ll find(ll u){
    if(u==par[u]) return u;
    return par[u]=find(par[u]);
}
void add(int u, int v){
    u=find(u);
    v=find(v);
    if(sz[u]>sz[v]){
        par[v]=u;
        sz[u]+=sz[v];
    }
    else{
        par[u]=v;
        sz[v]+=sz[u];
    }
}
unordered_map< ll ,vector <pair <ll,ll > > > canh;
set<ll> st;
vector <pair<ll, ll > > all;
void them1(int i,int j){
    int ts_t=a[i][j]  -     a[i+1][j];
    int ms_t=b[i+1][j]   -   b[i][j];
    if(ms_t==0&&ts_t==0){
        all.push_back({encode(i,j),encode(i+1,j)});
        return;
    }
    else if(ms_t==0&&ts_t!=0) return;
    int g=__gcd(ts_t,ms_t);        ts_t/=g;         ms_t/=g;
    if(ts_t*ms_t<0) return;
     int            ts_gt=ts_t,              ms_gt=ms_t;
    ts_gt*=b[i][j];
    g=__gcd(ts_gt,ms_gt);       ts_gt/=g;           ms_gt/=g;
    pair<ll,ll> sech= pluss(a[i][j],ts_gt,ms_gt);
    //  cout << i << " " << j << " " << i+1 << " " << j << " " << sech.first << " " << sech.second << endl;
    ll x=hasht(ts_t,ms_t,sech.first,sech.second);
    canh[x].push_back({encode(i,j),encode(i+1,j)});
    st.insert(x);
}
void them2(int i,int j){
    int ts_t=a[i][j]  -     a[i][j+1];
    int ms_t=b[i][j+1]   -   b[i][j];
    if(ms_t==0&&ts_t==0){
        all.push_back({encode(i,j),encode(i,j+1)});
        return;
    }
    else if(ms_t==0&&ts_t!=0) return;
    int g=__gcd(ts_t,ms_t);        ts_t/=g;         ms_t/=g;
    if(ts_t*ms_t<0) return;
     int            ts_gt=ts_t,              ms_gt=ms_t;
    ts_gt*=b[i][j];
    g=__gcd(ts_gt,ms_gt);       ts_gt/=g;           ms_gt/=g;
    pair<ll,ll> sech= pluss(a[i][j],ts_gt,ms_gt);
    //  cout << i << " " << j << " " << i+1 << " " << j << " " << sech.first << " " << sech.second << endl;
    ll x=hasht(ts_t,ms_t,sech.first,sech.second);
    canh[x].push_back({encode(i,j),encode(i,j+1)});
    st.insert(x);
}
vector<ll> p1,s1;
ll find1(ll u){
    if(p1[u]==u) return u;
    else return p1[u]=find1(p1[u]);
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=1000000;i++) {
        par[i]=i;
        sz[i]=1;
    }
    for(int i=1;i<=n;i++)    for(int j=1;j<=n;j++) cin >> a[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> b[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // them voi i+1,j
            
            if(i+1<=n){
                them1(i,j);
            }
            //them voi i,j+1
            
            if(j+1<=n){
                them2(i,j);
                
            }

        }
    }
    unordered_map<ll, int > vst;
    ll sol=1;
     for(auto j:all){
        ll u=j.first,v=j.second;
        vst[u]=1;
        vst[v]=1;
            // cout << decode(u).first << " " << decode(u).second << " va " << decode(v).first << " " << decode(v).second << "\n";
        u=find(u);
        v=find(v);
        if(u==v) continue;
        add(u,v);
        
        sol=max({sol,sz[u],sz[v]});
    }
    vector<ll> ngu(705*705), szngu;
    szngu.reserve(705*705);
    unordered_map<ll,int> nguid;
    nguid.reserve(705*705);
    ll C = 0;
    for(int x = 0; x < 705*705; x++){
        ll r = find(x);
        if(!nguid.count(r)){
            nguid[r] = C++;
            szngu.push_back(sz[r]);
        }
        ngu[x] = nguid[r];
    }
    p1.resize(C);
    s1.resize(C);
    
    
    for(auto i:st){
        // cout << i << ":\n";
        // if(canh[i].size()+all.size()<sol) continue;
        vector<ll> bat;
        bat.reserve(canh[i].size()*2);
        for(auto &e: canh[i]){
            ll cu = ngu[e.first];
            ll cv = ngu[e.second];
            if(cu!=cv){
                bat.push_back(cu);
                bat.push_back(cv);
            }
        }
        sort(bat.begin(), bat.end());
        bat.erase(unique(bat.begin(), bat.end()), bat.end());
        for(ll c: bat){
            p1[c] = c;
            s1[c] = szngu[c];
        }
        for(auto &e: canh[i]){
            ll u = ngu[e.first];
            ll v = ngu[e.second];
            if(u==v) continue;
            ll ru = find1( u);
            ll rv = find1( v);
            if(ru==rv) continue;
            p1[rv] = ru;
            s1[ru] += s1[rv];
            sol = max(sol,s1[ru]);
        }
       
    }
    cout << sol;
    return 0;
}
