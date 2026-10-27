#include <bits/stdc++.h>
#define int long long 
using ll=long long;
using namespace std;
int n,a[500005];
int dem[500005];
ll res=0;
int maxx=0;
int dnc(int l, int r){
    if(l>=r) return 0;
    int mid=(l+r)/2;
    ll ans= dnc(l,mid)+dnc(mid+1,r);
    // vector <int> dem(maxx+1),val;
    int maxx=0,gtri=0;
    ll bad=0;
    vector <int> cand;
    for(int i=mid;i>=l;i--) {
        dem[a[i]]++;
        if(dem[a[i]]>maxx){
            maxx=dem[a[i]];
            cand.push_back(a[i]);
        }
    }
    for(int i=l;i<=mid;i++) dem[a[i]]=0;
    maxx=0;
    for(int i=mid+1;i<=r;i++) {
        dem[a[i]]++;
        if(dem[a[i]]>maxx){
            maxx=dem[a[i]];
            cand.push_back(a[i]);
        }
    }
    for(int i=mid+1;i<=r;i++) dem[a[i]]=0;
    sort(cand.begin(),cand.end());
    cand.erase(unique(cand.begin(),cand.end()),cand.end());
    for(auto &g:cand){
        ll mn=0,mx=0;
        vector <ll> pre;
        pre.push_back(0);
        for(int k=l;k<=r;k++){
            if(a[k]==g) pre.push_back(pre.back()+1);
            else pre.push_back(pre.back()-1);
            mx=max(mx,pre.back());
            mn=min(mn,pre.back());
        }
        vector<int> pf(mx-mn+2);
        for(int k=l;k<=mid;k++) pf[pre[k-l]-mn+1]++;
        for(int k=1;k<pf.size();k++) pf[k]+=pf[k-1];
        for(int k=mid+1;k<=r;k++) bad+=pf[pre[k+1-l]-mn];
    }
    ans+=(mid-l+1)*(r-mid)-bad;
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        maxx=max(maxx,a[i]);
    }
    cout << dnc(1,n);
    return 0;
}