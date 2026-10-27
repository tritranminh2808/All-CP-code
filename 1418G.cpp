#include <bits/stdc++.h>
#define int long long
using namespace std;
int xo(int a, int b){
    int ans=0,mu=1;
    while(a||b){
        int x=a%3,y=b%3;
        ans+=(x+y)%3*mu;
        a/=3;b/=3;
        mu*=3;
    }
    return ans;
}
int a[500005],pre[500005];
unordered_map <int, int > cnt;
int n;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
long long ran(int l, int r){
    return l+rng()%(r-l+1);
}
unordered_map<int, long long > newv;
unordered_map<long long,bool> se;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=500000;i++){
        long long cc=ran(1,1e18);
        while(se[cc]==1)    cc=ran(1,1e18);
        newv[i]=cc;
        se[cc]=1;
    }
    // cout << 0;
    // return 0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        a[i]=newv[a[i]];
    }
    for(int i=1;i<=n;i++) pre[i]=xo(pre[i-1],a[i]);
    // int l=1;
    unordered_map<int, int > mp;
    mp[0]=1;
    int l=1;
    int ans=0;
    for(int r=1;r<=n;r++){
        cnt[a[r]]++;
        while(cnt[a[r]]>3){
            mp[pre[l-1]]--;
            cnt[a[l]]--;
            l++;
        }
        ans+=mp[pre[r]];
        mp[pre[r]]++;
    }
    cout << ans;
    return 0;
}