#include <bits/stdc++.h>
using namespace std;

const int mod = 9901;
long long st[1000005];
int n;
long long k;
void update(int i,int v){
    for(;i<=n;i+=i&-i) st[i]=(st[i]+v)%mod;
}
long long find(int i){
    long long s=0;
    for(;i>0;i-=i&-i) s=(s+st[i])%mod;
    return s;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;

    vector<long long> a(n), v;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int m = v.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int p=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
        long long lo=a[i]-k,hi=a[i]+k;

        int l=lower_bound(v.begin(),v.end(),lo)-v.begin()+1;
        int r=upper_bound(v.begin(),v.end(),hi)-v.begin();
        int s=0;
        if(l<=r ) s=(find(r) -find(l - 1) + mod) % mod;
        int f = (s + 1) % mod;
        update(p, f);
        ans = (ans + f) % mod;
    }

    ans = (ans - n % mod + mod) % mod;
    cout << ans;
}
