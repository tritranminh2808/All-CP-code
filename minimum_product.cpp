#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int a[1000005];
int binpow(int n, int k){
    int res=1;
    while(k>0){
        
        if(k%2==1) res=res*n%mod;
        k/=2;
        n=n*n%mod;
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        unordered_map<int,pair <int, int > > mp;
        for(int i=1;i<=n;i++) {
            cin >> a[i];
            vector <pair <int, int > > v;
            for(int j=2;j<=sqrt(a[i]);j++){
                if(a[i]%j==0){
                    // v.push_back({j,0});
                    int cnt=0;
                    while(a[i]%j==0) {
                        a[i]/=j;
                        cnt++;
                    }
                    v.push_back({j,cnt});
                }
            }
            if(a[i]!=1) v.push_back({a[i],1});
            for(auto j:v){
                // cout << j.first << " " << j.second << "\n";
                mp[j.first].first+=j.second;
                mp[j.first].second=max(mp[j.first].second,j.second);
                // mp[j]/=2;
            }
        }
        long long sol=1;
        for(auto i:mp)  {
            int mu=0;
            if(i.second.second*2>i.second.first) mu=i.second.second*2-i.second.first;
            else mu=i.second.first%2;
            sol=(sol*binpow(i.first,max((int)0,mu)))%mod;
        }
        cout << sol << "\n";
    }
    return 0;
}