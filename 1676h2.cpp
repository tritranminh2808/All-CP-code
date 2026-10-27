#include <bits/stdc++.h>
using namespace std;
int st[200005];
int n;
void update(int i, int v){
    for(;i<=n;i+=i&-i) st[i]+=v;
}
int find(int i){
    int res=0;
    for(;i>0;i-=i&-i) res+=st[i];
    return res;
}
int a[200005];
void cok(){
    cin >> n;
    for(int i=0;i<=n;i++) st[i]=0;
    for(int i=1;i<=n;i++) cin >> a[i];
    long long res=0;
    for(int i=n;i>=1;i--){
        res+=find(a[i]);
        update(a[i],1);
    }
    //long long ans=res*(res-1)/2;
    cout << res << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) cok();
    return 0;
}