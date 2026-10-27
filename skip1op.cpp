#include <bits/stdc++.h>
using namespace std;
int b[200005],a[200005],ans[200005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) b[i]=i;
    for(int i=1;i<=m;i++) {
        cin >> a[i];
        swap(b[a[i]],b[a[i]+1]);
    }
    for(int i=1;i<=n;i++) ans[b[i]]=i;
    for(int i=1;i<=n;i++) b[i]=i;
    for(int i=1;i<=m;i++){
        int x=a[i];
        // cout << b[x] << " " << b[x+1] << "\n";
        if(b[x]!=1&&b[x+1]!=1) cout << ans[1] << "\n";
        else if(b[x]==1) cout << ans[b[x+1]] << "\n";
        else if(b[x+1]==1) cout << ans[b[x]] << "\n";
        swap(b[x],b[x+1]);

    }
}