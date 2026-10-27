#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
vector <int> adj[100005];
int a[100005];
signed main(){
    freopen("gcdix.inp","r",stdin);
	freopen("gcdix.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while(q--){
        int typ; cin >> typ;
        if(typ==1){
            int l,r,k; cin >> l >> r >> k;
            int x=l,y=r;
            while(x!=y){
                if(x>y) {
                    a[x]+=k;
                    x/=2;
                }
                else{
                    a[y]+=k;
                    y/=2;
                }
            }
            a[x]+=k;
        }
        else{
            int u,v; cin >> u >> v;
            int x=u,y=v;
            int ans=0;
            while(x!=y){
                if(x>y) {
                    ans=__gcd(a[x],ans);
                    x/=2;
                }
                else{
                    ans=__gcd(ans,a[y]);
                    y/=2;
                }
            }
            ans=__gcd(ans,a[x]);
            cout << ans << "\n";
        }
    }
    return 0;
}