#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],b[200005];
int n,k;
void cok(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> b[i];
    int cnt=1;
    a[1]=1;
    for(int i=2;i<=n;i++){
        if(b[i]-b[i-1]==i) {
            cnt++;
            a[i]=cnt;
        }
        else a[i]=a[i-b[i]+b[i-1]];
    }
    for(int i=1;i<=n;i++) cout << a[i] << " ";
    cout <<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) cok();
    return 0;
}