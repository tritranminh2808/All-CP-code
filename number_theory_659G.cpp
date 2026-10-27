#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int a[1000005],premul[1000005];
int power(int n, int k){
    if(k==0) return 1;
    if(k==1) return n%mod;
    int tmp=power(n,k/2);
    tmp=(tmp*tmp)%mod;
    if(k%2==1) tmp=(tmp*n)%mod;
    return tmp%mod;
}
int f[1000005];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n ;
    for(int i=1;i<=n;i++) cin >> a[i];
    a[0]=INT_MAX;
    a[n+1]=INT_MAX;
    f[2]=min(a[2]-1,a[1]-1);
    for(int i=3;i<=n;i++) f[i]=(f[i-1]*min({a[i-2]-1,a[i-1]-1,a[i]-1}) +min(a[i]-1,a[i-1]-1))%mod;
    int sol=a[1]-1;
    for(int i=2;i<=n;i++){
        sol=(sol+f[i]*min(a[i-1]-1,a[i]-1)+a[i]-1)%mod;
    }
    cout << sol;
    return 0;
}