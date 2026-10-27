#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("subseq.inp","r",stdin);
    freopen("subseq.out","w",stdout);
    int n,k; cin >> n >> k;
    vector <int > a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    int l=1,r=1,cur=0,sol=0,cnt=0;
    map<int, int> mp;
    while(r<=n){
        mp[a[r]]++;
        if(mp[a[r]]==1) cnt++;
        if(cnt<=k) sol=max(sol,r-l+1);
        else {
            while(cnt>k){
                mp[a[l]]--;
                if(mp[a[l]]==0) cnt--;
                l++;
            }
        }
        r++;
    }
    cout << sol;
    return 0;
}