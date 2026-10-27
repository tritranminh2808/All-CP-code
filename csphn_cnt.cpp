#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
int gt[2000005],tg[2000005];;
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
int dp[5005];
int cal(pair <int, int > a, pair <int, int > b){
    int dx=b.first-a.first,dy=b.second-a.second;
    return ckn(dx+dy,dx);
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    gt[0]=1;
    for(int i=1;i<=2000000;i++) gt[i]=gt[i-1]*i%mod;
    tg[2000000]=power(gt[2000000],mod-2);
    for(int i=2000000-1;i>=0;i--) tg[i]=tg[i+1]*(i+1)%mod;
    int n,m,k; cin >> n >> m >> k;
    vector <pair <int, int > > a(k+1);
    a[0]={n,m};
    for(int i=1;i<=k;i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(),a.end());
    int id=0;
    for(int i=0;i<=k;i++) if(a[i].first==n&&a[i].second==m){id=i;break;}
    for(int i=0;i<=k;i++){
        int w=cal({1,1},a[i]);
        int sum=0;
        for(int j=0;j<i;j++){
            // if(a[j].first<=a[i].first)
            int w2=cal(a[j],a[i]);
            int t=(dp[j]*w2)%mod;
            sum=(sum+t)%mod;
        }
        dp[i]=(w-sum+mod)%mod;
    }
    cout << dp[id]%mod;
    return 0;
}