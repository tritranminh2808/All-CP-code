#include <bits/stdc++.h>
using namespace std;
int par2[200005], par[200005], sz[200005], p[200005], lv[200005], it = 0;
 
int find2(int u) {
    if(u==par2[u]) return u;
    return par2[u]=find2(par2[u]);
}
 
int find(int u) {
    u=find2(u);
    if(u==par[u]) return u;
    return par[u]=find(par[u]);
}
 
void cham(int u) {
    u=find2(u);
    int r=u, cc=0;
    while (u>0) {
        int v=find2(p[u]);
        p[u]=cc;
        par[u]=r;
        cc=u;
        u=v;
    }
    sz[r]=sz[cc];
}
 
int xl(int a, int b) {
    ++it;
    vector<int> va, vb;
    int l=0;
    while (l==0) {
        if (a>0) {
            a=find2(a);
            va.push_back(a);
            if (lv[a] == it) { 
                l=a; 
                break; 
            }
            lv[a]=it;
            a=p[a];
        }
        if (b>0) {
            b=find2(b);
            vb.push_back(b);
            if (lv[b] == it) { 
                l=b; 
                break; 
            }
            lv[b]=it;
            b=p[b];
        }
    }
 
    int cnt=0;
    for (auto i: va) {
        par2[i]=l;
        if (i==l) break;
        ++cnt;
    }
    for (auto i:vb) {
        par2[i]=l;
        if (i==l) break;
        ++cnt;
    }
    return cnt;
}
 
int add(int a, int b) {
    a=find2(a);
    b=find2(b);
    if (a==b) return 1;
    int ca=find(a),cb=find(b);
    if (ca!=cb) {
        if (sz[ca]>sz[cb]) swap(a,b),swap(ca,cb);
        cham(a);
        p[a]=b;
        par[a]=b;
        sz[cb]+=sz[a];
        return 0;
    }
    return xl(a,b)+1;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    for (int i = 1; i <= n; ++i) {
        par2[i]=par[i]=i;
        sz[i]=1;
    }
 
    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << add(u, v) << '\n';
    }
    return 0;
}