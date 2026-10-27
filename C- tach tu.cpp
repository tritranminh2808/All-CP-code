#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;
const int mod=1e9+7,base=257;
gp_hash_table<int,bool> dict;
int power[200005];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin >> n;
    power[0]=1;
    for(int i=1;i<=200000;i++) power[i]=power[i-1]*base%mod;
    for(int i=1;i<=n;i++){
        string s; cin >> s;
        int t=0;
        for(auto j:s) t=(t*base+j+1)%mod;
        dict[t]=1;
    }   
    int q; cin>> q;
    while(q--){
        string s; cin >> s;
        int n=s.length();
        s='!'+s;
        vector <int> dp(n+1,-1),hs(n+1);
        for(int i=1;i<=n;i++) hs[i]=(hs[i-1]*base+s[i]+1)%mod;
        dp[0]=0;
        for(int i=1;i<=n;i++) {
            for(int j=i-1;j>=0;j--){
                int k=(hs[i]-hs[j]*power[i-j])%mod;
                if(k<0) k+=mod;
                if(dict[k]&&dp[j]>=0){
                    dp[i]=j;
                    break;
                }
            } 
        }
        if(dp[n]==-1) {
            cout << "-1\n";
            continue;
        }
        vector <int> trace;
        int cur=n;
        while(cur>0){
            trace.push_back(cur);
            cur=dp[cur];
        }
        reverse(trace.begin(),trace.end());
        int id=0;
        string r;
        vector <string> ans;
        for(int i=1;i<=n;i++){
            
            r+=s[i];
            if(i==trace[id]){
                id++;
                ans.push_back(r);
                r.clear();
                // cout << 
            }
        }
        for(auto i:ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}