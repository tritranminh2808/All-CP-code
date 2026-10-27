#include <bits/stdc++.h>
using namespace std;
#define int long long
int gt[1000005],tg[1000005];
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
int ckn(int k, int n){
    if(k>n||n<0||k<0) return 0;
    return gt[n]*tg[k]%mod*tg[n-k]%mod;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    gt[0]=1;
    for(int i=1;i<=1000000;i++) gt[i]=gt[i-1]*i%mod;
    tg[1000000]=binpow(gt[1000000],mod-2);
    for(int i=1000000-1;i>=0;i--) tg[i]=tg[i+1]*(i+1)%mod;
    int n; cin >> n;
    if(n%2==1){
        cout << 0;
        return 0;
    }
    string s; cin >> s;
    int k=0;
    n-=s.length();
    for(auto i:s){
        if(i=='(') k++;
        else k--;
        if(k<0){
            cout << 0;
            return 0;
        }
    }
    // cout << k;
    cout << (ckn((n-k)/2,n)-ckn((n-k)/2-1,n)+mod)%mod;
    return 0;;

}