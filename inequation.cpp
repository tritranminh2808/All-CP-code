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
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,p; cin >> n >> k ;
    gt[0]=1;
    for(int i=1;i<=2000000;i++) gt[i]=gt[i-1]*i%mod;
    tg[2000000]=power(gt[2000000],mod-2);
    for(int i=2000000-1;i>=0;i--) tg[i]=tg[i+1]*(i+1)%mod;
    int sol=0;
    for(int i=0;i<=n;i++) sol=(sol+ckn(i+k-1,k-1))%mod;
    cout << sol;
    return 0;
}