#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
int d[500005];
int pre[500005],maxx[500005],a[500005];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++) {
        cin >> d[i];
        pre[i]=pre[i-1]+d[i]+1;
    }
    for(int i=1;i<=n;i++) maxx[i]=max(maxx[i-1],pre[i]-i);
    for(int i=0;i<=n;i++) a[i]=maxx[i]-pre[i];
    sort(a,a+n+1);
    while(q--){
        int t,l,r; cin >> t >> l >> r;
        l-=t;
        r-=t;
        auto it1=lower_bound(a,a+n+1,l);
        auto it2=upper_bound(a,a+n+1,r);
        cout << it2-it1 << "\n";
    }
    return 0;
}