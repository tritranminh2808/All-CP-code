#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans=0;
map <int, int > mp;
multiset <int> st;
void add(int x, int y){
    auto it=mp.lower_bound(x);
    if(it!=mp.begin()) --it;
    while(it!=mp.end()){
        if(it->second<x){ ++it; continue; }
        if(it->first>y) break;
        x=min(x, it->first);
        y=max(y, it->second);
        st.erase(st.find(it->second-it->first));
        auto nxt=it++;
        mp.erase(nxt);
    }
    mp[x]=y;
    st.insert(y-x);
    ans=max(ans,*st.rbegin());
}
void cok(){
    int n; cin>> n;
    mp.clear();
    st.clear();
    ans=0;
    vector <int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    int suma=0,sumb=0;
    
    for(int i=1;i<=n;i++){
        suma+=a[i];
        sumb+=b[i];
        add(b[i],a[i]);
        cout << suma-sumb-ans << " ";
    }
    cout << "\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cok();
    }
    return 0;
} 