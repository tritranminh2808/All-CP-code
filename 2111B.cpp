#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll f[12];
struct S { ll w,l,h; };
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    f[1]=1; f[2]=2;
    for(int i=3;i<=10;i++) f[i]=f[i-1]+f[i-2];
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        string ans;
        while(m--){
            ll W,L,H; cin>>W>>L>>H;
            if(H < f[n]){
                ans.push_back('0');
                continue;
            }
            vector<S> v;
            v.push_back({W,L,H});
            bool ok=1;
            for(int i=n;i>=1;i--){
                ll s = f[i];
                int idx = -1;
                ll best = -1;
                for(int j=0;j<(int)v.size();j++){
                    if(v[j].w>=s && v[j].l>=s && v[j].h>=s){
                        ll area = v[j].w * v[j].l;
                        if(area>best){
                            best = area;
                            idx = j;
                        }
                    }
                }
                if(idx<0){
                    ok = false;
                    break;
                }
                S c = v[idx];
                v.erase(v.begin()+idx);
                ll w=c.w, l=c.l, h=c.h;
                if(w-s>0 && s>0 && h>0) v.push_back({w-s, s, h});
                if(w>0 && l-s>0 && h>0) v.push_back({w, l-s, h});
                if(s>0 && s>0 && h-s>0) v.push_back({s, s, h-s});
            }
            if(ok) ans+='1';
            else ans+='0';
        }
        cout<<ans<<"\n";
    }
    return 0;
}

