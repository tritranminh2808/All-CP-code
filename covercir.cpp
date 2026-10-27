#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,u,v; 
long long dist(int l, int r){
    if(l>r) r+=n;
    return r-l;
}
signed main(){
    freopen("covercir.inp","r",stdin);
    freopen("covercir.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n>> u >> v;
        if(n<=5005){
            if(u>v) swap(u,v);
            int l=v+1;
            int cc=n+u-v;
            long long ans=1e16;
            while(cc--){
                for(int r=u;r<=v;r++){ // u quan li tu r den l, v quan li tu r+1 den l-1
                    // cout << l << " " << r << endl;
                    long long dem=max(dist(l,r)+min(dist(l,u),dist(u,r)), dist(r+1,l-1)+min(dist(r+1,v),dist(v,l-1)));
                    if(ans>dem){
                        // cout <<l << " " << r << " " << dist(l,r)+min(dist(l,u),dist(u,r)) << " " << dist(r+1,l-1)+min(dist(r+1,v),dist(v,l-1)) << "\n";
                    }
                    ans=min(ans,dem);
                }
                l++;
                if(l>n)l=1;
            }
            cout << ans << "\n";
            continue;
        }
        int r=(v+u)/2;
        int l=((n+u-v)/2+v)%n;
        // cout << l << " " << r << endl;
        cout<< min(max(dist(l,r)+min(dist(l,u),dist(u,r)), dist(r+1,l-1)+min(dist(r+1,v),dist(v,l-1))),n/2) << "\n";
    }
    return 0;
}