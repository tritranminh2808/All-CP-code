#include <bits/stdc++.h>
#define int long long
using namespace std;
int sech[(1<<20)+5];
const int mod=1e9+7;
int bp(int a, int n) {
    if (n == 1) {
        return a;
    }
    int tmp = bp(a, n / 2);
    tmp*=tmp;
	tmp%=mod;
    if (n % 2 == 1) tmp=tmp*a%mod;
    return tmp%mod;
}
int bp2(int a, int n){
    int x=1;
    while(n>0){
        if(n%2==1) x=x*a%mod;
        n=n/2;
        a=a*a%mod;
    }
    return x;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        cout << bp(2,n-1)*n%mod << "\n";
    }
    return 0;
}
