#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
const int pp=3e5+5;
int gt[pp],tg[pp];
int cnt[pp];
int dp[11][pp];
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
ll ckn(ll n, ll k)
{
    if (n < 0 || k < 0 || k > n)  return 0;
    return gt[n] * tg[k] %mod*tg[n-k]%mod;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>> a[i];
        cnt[a[i]]++;
    }
    int gg=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            cout << 1; return 0;
        }
        gg=__gcd(gg,a[i]);
    }
    gt[0]=1;
    for(int i=1;i<=300000;i++) gt[i]=gt[i-1]*i%mod;
    tg[300000]=power(gt[300000],mod-2);
    for(int i=300000-1;i>=0;i--) tg[i]=tg[i+1]*(i+1)%mod;
    if(gg>1){
        cout << -1;
        return 0;
    }
    for(int i=1;i<300001;i++){
        for(int j=i*2;j<300001;j+=i)cnt[i]+=cnt[j];
    }
    for(int lay=2;lay<=10;lay++){
        for(int i=pp-6;i>=1;i--){
            dp[lay][i]=ckn(cnt[i],lay);
            for(int j=i*2;j<pp-5;j+=i){
                dp[lay][i]-=dp[lay][j];
                if(dp[lay][i]<0) dp[lay][i]+=mod;
            }
        }
        if(dp[lay][1]>0) {
            cout << lay ;
            return 0;
        }

    }
    return 0;
}