#include <bits/stdc++.h>
using namespace std;
// #define int long long
using ll=long long;
ll gt[1000005],tg[1000005];
const int mod=1e9+7;
ll power(ll a, int k){
    ll res=1;
    while(k>0){
        if(k%2==1) res=res*a%mod;
        a=a*a%mod;
        k/=2; 
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    gt[0]=1;
    for(int i=1;i<=1000000;i++) gt[i]=gt[i-1]*i%mod;
    tg[1000000]=power(gt[1000000],mod-2);
    for(int i=1000000-1;i>=0;i--) tg[i]=tg[i+1]*(i+1)%mod;
    int n; cin>> n;
    vector <int> a;
    unordered_map<int,int> f;
    for(int i=0;i<n;i++){
        int u; cin >> u ;
        f[u]++;
        a.push_back(u);
    }
    int sol=gt[n];
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    for(auto i:a) sol=sol%mod*tg[f[i]]%mod;
    cout << sol%mod;
    return 0;
}