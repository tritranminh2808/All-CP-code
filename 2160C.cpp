#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int n,k;
void cok(){
    cin >> n;
    vector <int> v;
    bool oo=0;
    for(int i=1;i<=63;i++){
        if(n>=(1LL<<i)) continue;
        bool ok=1;
        for(int j=0;j<i;j++){
            if(((n>>j)&1)!=((n>>(i-j-1))&1)){
                ok=0;
                break;
            }
        }
        if(!ok) continue;
        if(i%2)    if((n>>((i-1)/2))&1) ok=0;
        if(ok){
            oo=1;
            break;
        }
    }
    if(oo) cout << "YES\n";
    else cout << "NO\n";
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) cok();
    return 0;
}