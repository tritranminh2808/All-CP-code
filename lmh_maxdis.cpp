#include <bits/stdc++.h>
#define int long long
using ull=unsigned long long;
using ll=long long;
using namespace std;
int a[1000005];
uint64_t  dis(int64_t a, int64_t b)
{
    return b-a;
}

int64_t mid(int64_t a, int64_t b)
{
    int64_t hd = dis(a, b) / 2;   
    return b - hd;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,l,r;cin >> n >> l >> r;
    for(int i=1;i<=n;i++) cin >> a[i];
    ull ml=1e20,mr=1e20;
    for(int i=1;i<=n;i++) {
        
        ml=min(ml,ull(fabsl(l-a[i])));
        mr=min(mr,ull(fabsl(r-a[i])));
    }
    int maxx=0,sol=0;
    if(maxx<ml){
        maxx=ml;sol=l;
    }
    if(maxx<mr){
        maxx=mr;sol=r;
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        int tbc=mid(a[i-1],a[i]);
        if(tbc<l||tbc>r) continue;
        ll x1=fabsl(ll(tbc-a[i])),x2=fabsl(ll(tbc-a[i-1]));
        ll xet=min(x1,x2);
        if(maxx<xet){
            maxx=xet;
            sol=tbc;
        }
        else if(maxx==xet) sol=max(sol,tbc);
    }
    cout << sol;
}