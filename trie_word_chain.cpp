#include <bits/stdc++.h>
// #define int long long
using namespace std;
int node=0;
int st[26][1000005];
int dp[1000005],kthuc[1000005];
int update(string s){
    int id=0;
    int cur=0;
    for(int i=0;i<s.length();i++){
        int nid=st[s[i]-'a'][id];
        if(nid==-1){
            st[s[i]-'a'][id]=++node;
            nid=node;
        }
        if(kthuc[id]) cur=max(cur,dp[id]);
        // cnt[nid]++;
        id=nid;
    }
    dp[id]=cur+1;
    kthuc[id]=1;
    return dp[id];
}
string a[1000005];
bool cmp(string a, string b){
    return a.length()<b.length();
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    memset(st,-1,sizeof(st));
    cin >> q;
    int sol=0;
    for(int i=1;i<=q;i++) cin >> a[i];
    sort(a+1,a+q+1,cmp);
    for(int i=1;i<=q;i++){
        sol=max(sol,update(a[i]));
    }
    cout << sol;
    return 0;
}