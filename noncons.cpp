#include <bits/stdc++.h>
#define int long long
using namespace std;
int f[2005][2005][2];
int a[2005];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin >> n;
    for(int i=0;i<=2001;i++){
        for(int j=0;j<=2001;j++) {
            f[i][j][0]=-1e16;
            f[i][j][1]=-1e16;
        }
    }
    for(int i=1;i<=n;++i) cin >> a[i];
    k=(n+1)/2;
    int maxx=0;
    for(int i=1;i<=n;i++){
        maxx=max(maxx,a[i]);
        f[i][1][0]=max(f[i-1][1][0],f[i-1][1][1]);
        f[i][1][1]=maxx;
    }
    for(int j=2;j<=k;j++){
        for(int i=1;i<=n;i++) {
            f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]);
            if(i>=2) f[i][j][1]=max(f[i-2][j-1][0],f[i-2][j-1][1])+a[i];
        }
    }
    for(int i=1;i<=k;i++) cout << max(f[n][i][0],f[n][i][1]) << "\n";
    return 0;
}