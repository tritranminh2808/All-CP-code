#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4.2,popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wformat-security"
using namespace std;
using ll=long long;
struct pl{
    ll x,g,r;
};
struct cute{
    ll t, b, w1,w2;
};
bool cmp(cute a, cute c){
    return a.b<c.b;
}
struct fentri{
    int n;
    vector <ll> st;
    fentri(): n(0) {}
    void setup(int nn){
        n=nn;
        st.assign(n+5,1e16);
    }
    
    void update(int i, ll v){
        for(;i<=n;i+=i&-i) st[i]=min(st[i],v);
    }
    ll find(int i){
        ll res=1e16;
        for(;i>0;i-=i&-i) res=min(res,st[i]);
        return res;
    }

};
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
    int t;
    if (!readInt(t)) return 0;
    string out;
    out.reserve(1<<20);
    while(t--){
        int n; readInt(n);
        vector <pl> a(n+1);
        vector <cute> v(n+1);
        vector <ll> prer(n+1),preg(n+1);
        vector <ll> b;
        for(int i=1;i<=n;i++) {
            readInt(a[i].x);
            readInt(a[i].g);
            readInt(a[i].r);
            prer[i]=prer[i-1]+a[i].r;
            preg[i]=preg[i-1]+a[i].g;
            v[i].t=prer[i]-a[i].x;
            v[i].b=prer[i-1]-a[i].x;
            v[i].w2=preg[i];
            v[i].w1=preg[i-1];
            b.push_back(v[i].t);
            b.push_back(v[i].b);
        }
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        for(int i=1;i<=n;i++){
            v[i].t = (ll)(lower_bound(b.begin(), b.end(), v[i].t) - b.begin() + 1);
            v[i].b = (ll)(lower_bound(b.begin(), b.end(), v[i].b) - b.begin() + 1);
        }
        // sort(v.begin()+1,v.end(),cmp);
        ll sol=-1e16;
        fentri f;
        f.setup(b.size());
        // f.update(v[1].b, v[1].w1);
        for(int i=1;i<=n;i++){
            f.update(v[i].b,v[i].w1);
            sol=max(sol,v[i].w2-f.find(v[i].t));
            
        }
        out += to_string(sol);
        out.push_back('\n');

    }
    fwrite(out.c_str(), 1, out.size(), stdout);
    return 0;
}