#include <bits/stdc++.h>
using namespace std;
#define int long long
int gt[200005],tg[200005];
const int mod=1e9+7;
int binpow(int n,int k){
    int res=1;
    while(k){
        if(k%2==1) res=res*n%mod;
        n=n*n%mod;
        k/=2;
    }
    return res;
}
int ckn(int n, int k){
    if(k>n) return 0;
    return gt[n]*tg[k]%mod*tg[n-k]%mod;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    gt[0]=1;
    for(int i=1;i<=200000;i++) gt[i]=gt[i-1]*i%mod;
    tg[200000]=binpow(gt[200000],mod-2);
    for(int i=200000-1;i>=0;i--) tg[i]=tg[i+1]*(i+1)%mod;
    int n,k; cin >> n>> k;
    cout << ckn(2*n,n)*binpow(n+1,mod-2)%mod*binpow(k,n)%mod;
    return 0;;

}