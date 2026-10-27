#include <bits/stdc++.h>
#define int long long 
using namespace std;
int f[500005][31],g[500005][31];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,q; cin >> n >> q;
        for(int i=1;i<=n;i++){
            for(int j=0;j<31;j++){
                f[i][j]=0;
                g[i][j]=0;
            }
        }
        vector <int> a(n+1),khong(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++){
            khong[i]=khong[i-1];
            if(a[i]==0) khong[i]++;
            int cc=-1;
            if(a[i]!=0) cc=31- __builtin_clz(a[i]);
            for(int j=0;j<31;j++){
                f[i][j]=f[i-1][j];
                g[i][j]=g[i-1][j];
            }
            if(a[i]==0) continue;
            f[i][cc]++;
            for(int j=0;j<31;j++){
                if(j!=cc&&((a[i]>>j)&1)) g[i][j]++;
            }
        }
        while(q--){
            int l,r;
            cin >> l >> r;
            long long sol=0;
            for(int i=0;i<31;i++){
                sol+=(f[r][i]-f[l-1][i])*(g[r][i]-g[l-1][i]);
            }
            sol+=(khong[r]-khong[l-1])*(r-l+1);
            cout << sol << "\n";
        }
    }
    return 0;
}   