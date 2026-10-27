#include <bits/stdc++.h>
using namespace std;
#define int long long
int gt[1000005];
const int mod=1e9+7;
int power(int a, int k){
    if(k==1) return a%mod;
    int tmp=power(a,k/2);
    tmp=(tmp*tmp)%mod;
    if(k%2==1) tmp=(tmp*a)%mod;
    return tmp%mod;
}
int ckn(int n, int k){
    if(k>n) return 0;
    return gt[n]%mod*(power(gt[k]*gt[n-k]%mod,mod-2))%mod;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,p; cin >> n >> k >> p;
    gt[0]=1;
    for(int i=1;i<=1000000;i++) gt[i]=gt[i-1]*i%mod;
    if(n<k*p){
        cout << 0;
        return 0;
    }
    cout << ckn(n-k*p+k-1,k-1);
    return 0;
}