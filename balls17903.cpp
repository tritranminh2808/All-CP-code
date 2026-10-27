#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<ll> v(n);
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++) cin>>c[i];
    while(q--){
        ll A,B;
        cin>>A>>B;
        vector<ll> f(n+1, -1e18);
        pair<int,ll> m1= {0,0}, m2={0,-1e18};
        ll sol=0;
        for(int i=0;i<n;i++){
            ll t1=(f[c[i]]==-1e18 ? -1e18:(f[c[i]] + A*v[i]));
            ll t2 = ((m1.first!=c[i]?m1.second:m2.second)+B*v[i]);
            ll cur=max(t1,t2);
            if(cur>f[c[i]]){
                f[c[i]]=cur;
                if(c[i]==m1.first) m1.second=cur;
                else if(cur>m1.second){
                    m2=m1;
                    m1={c[i],cur};
                } 
				else if(cur>m2.second) m2={c[i],cur};
            }
            sol=max(sol,cur);
        }
        cout<< sol << "\n";
    }
    return 0;
}

