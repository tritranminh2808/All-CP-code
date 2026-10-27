#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
const int mod = 1e9+7;
int a[100005];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        string s;cin>>s;
        for(int j=0;j<c;j++) if(s[j]=='.') a[j]|=(1<<i);
    }
    ll ans=0;
    vector<int> t(c);
    for(int mask=0;mask<(1<<r);mask++){
        for(int j=0;j<c;j++){
            int m=a[j]&(~mask),c=__builtin_popcount(m);
            if(c==0) t[j]=0;
            else t[j]=((1LL<<c)-1)%mod;
        }
        ll dp0=1,dp1=t[0];
        for(int j=1;j<c;j++){
            ll n0 = dp1;
            ll n1=((dp0+dp1)%mod * t[j] )%mod;
            dp0=n0; dp1=n1;
        }
        ll g=(dp0+dp1)%mod;
        if(__builtin_popcount(mask)%2==1) ans=(ans-g+mod)%mod;
        else ans=(ans+g)%mod;
    }
    cout << ans;
    return 0;
}