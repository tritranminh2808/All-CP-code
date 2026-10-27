#include <bits/stdc++.h>
#define int long long
using namespace std;
pair <int ,int > a[200005];
int maxx;
int st[200005];
void update(int i, int v){
    for(;i<=maxx+5;i+=i&-i) st[i]+=v;
}
int find(int i){
    int res=0;
    for(;i>0;i-=i&-i) res+=st[i];
    return res;
}
void cok(){
    int n; cin >> n;
    vector <int> b,c;
    for(int i=1;i<=n;i++) {
        cin >> a[i].first >> a[i].second;
        b.push_back(a[i].first);
        c.push_back(a[i].second);
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    maxx=0;
    for(int i=1;i<=n;++i){
        a[i].first=lower_bound(b.begin(),b.end(),a[i].first)-b.begin()+1;
        a[i].second=lower_bound(c.begin(),c.end(),a[i].second)-c.begin()+1;
        maxx=max(maxx,a[i].second);
    }
    sort(a+1,a+n+1);
    for(int i=0;i<=maxx;i++) st[i]=0;
    int ans=0;
    for(int i=1;i<=n;i++){  
        ans+=find(maxx)-find(a[i].second-1);
        update(a[i].second,1);
    }
    cout << ans << "\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>> t;
    while(t--){
        cok();
    }
    return 0;
}