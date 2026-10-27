#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,x,y,u,v;
ll cal(ll u,bool ch){
    
    ll xx=u/(x+y);
    // cout << u << " " << x << " ";
    ll p=u%(x+y);
    ll ans=xx*2;
    if(ch&&p<=y) return ans+1;
    if(!ch&&p<=x) return ans+1;
    return ans+2;
}
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int ran(){
    return rng()%2;
}
int main(){
    ios_base::sync_with_stdio(0);
    
    cin >> n >> x >> y >> u >> v;
    if(n>=100000005){
        int gu=u,gv=v;
        if(u>=n/2) u=n-u+1;
        if(v>=n/2) v=n-v+1;
        int l1=cal(u,u==gu);
        int l2=cal(v,v==gv);
        int g1=ran();
        if(gu==u) cout << "B\n";
        else cout << "A\n";
        cout << l1 << "\n";
        // int g2=ran();
        if(gv==v) cout << "A\n";
        else cout << "B\n";
        cout << l2;
        return 0;
    }
    unordered_map<ll, pair <char , ll> > mp;
    ll r=n,l=1;
    for(int i=1;i<=n;i++){
        if(r<l) break;
        if(i%2==1){
            for(int j=0;j<x;j++){
                if(r<l) break;
                mp[r]={'A',i};
                r--;
            }
            for(int j=0;j<y;j++){
                if(r<l) break;
                mp[l]={'B',i};
                l++;
            }
        }
        else{
            for(int j=0;j<y;j++){
                if(r<l) break;
                mp[r]={'B',i};
                r--;
            }
            for(int j=0;j<x;j++){
                if(r<l) break;
                mp[l]={'A',i};
                l++;
            }
        }
    }
    cout << mp[u].first << "\n" << mp[u].second << "\n" << mp[v].first << "\n" << mp[v].second;
    return 0;
}