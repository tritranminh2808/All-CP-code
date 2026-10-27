#include <bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(pair <int, int> a, pair <int, int > b){
    return a.first*b.second<a.second*b.first;
}
bool cmp2(pair <int, int> a, pair <int, int > b){
    return a.first*b.second>a.second*b.first;
}
int f[100005],g[100005];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,w;
    cin >> n >> w;
    vector<pair <int, int > > a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    if(w==0){
        vector<pair<int, int > > dp;
        for (auto x:a) {
            auto it = lower_bound(dp.begin(), dp.end(), x,cmp);
            if (it == dp.end()) dp.push_back(x);
            else *it = x;
        }
        cout << dp.size() ;
        return 0;
    }
    vector<pair<int, int > > dp,b=a;
    int ii=0;
    for (auto &x:a) {
        if(x.first>x.second) swap(x.first,x.second);
        auto it = lower_bound(dp.begin(), dp.end(), x,cmp);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
        f[ii]=dp.size();
        ii++;
    }
    reverse(b.begin(),b.end());
    ii=n-1;
    dp.clear();
    for (auto &x:b) {
        if(x.first<x.second) swap(x.first,x.second);
        auto it = lower_bound(dp.begin(), dp.end(), x,cmp2);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
        g[ii]=dp.size();
        ii--;
    }
    int sol=0;
    for(int i=0;i<n;i++) sol=max(sol,g[i]+f[i]-1);
    cout << sol;
    return 0;
}

