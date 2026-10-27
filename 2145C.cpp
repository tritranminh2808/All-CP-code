#include <bits/stdc++.h>
using namespace std;
#define int long long
int st[200005];
int n,k;
int a[200005],b[200005];
void cok(){
    cin >>n;
    for(int i=0;i<=n;i++){
        a[i]=0;
        b[i]=0;
    }
    unordered_map<int, int > val;
    string s; cin >> s;
    s='!'+s;
    for(int i=1;i<=n;i++){
        a[i]=a[i-1];
        b[i]=b[i-1];
        if(s[i]=='a') a[i]++;
        else b[i]++;
    }
    int res=INT_MAX;
    val[0]=n+1;
    for(int i=n;i>=1;i--){
        if(val.find(a[i]-b[i])!=val.end())res=min(res,val[a[i]-b[i]]-i-1);
        val[b[n]-b[i-1]-a[n]+a[i-1]]=i;
        if(b[n]-b[i-1]-a[n]+a[i-1]==0) res=min(res,i-1);
    }
    if(res<INT_MAX)cout << res << "\n";
    else cout << "-1\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) cok();
    return 0;
}