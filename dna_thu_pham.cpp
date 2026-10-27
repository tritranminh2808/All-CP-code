#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int a[100005],c[100005],g[100005],t[100005];
int v[5005][5005];
const int base=257,mod=1e9+7;
int hs[100005];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        string s; cin >> s;
        for(int j=1;j<=m;j++) v[i][j]=s[j-1];
    }
    hs[0]=1;
    int s=0;
    for(int i=1;i<=n;i++){
         hs[i]=hs[i-1]*base%mod;
         s+=hs[i];
         s%=mod;
    }
    s*=k;
    s%=mod;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(v[j][i]=='A') a[i]=(a[i]+hs[j])%mod;
            else if (v[j][i]=='C') c[i]=(c[i]+hs[j])%mod;
            else if(v[j][i]=='G') g[i]=(g[i]+hs[j])%mod;
            else t[i]=(t[i]+hs[j])%mod;
        }
    }
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=m;j++){
            if(v[i][j]=='A') sum+=g[j]+c[j]+t[j];
            else if(v[i][j]=='C') sum+=g[j]+a[j]+t[j];
            else if(v[i][j]=='G') sum+=a[j]+c[j]+t[j];
            else  sum+=g[j]+c[j]+a[j];
            sum%=mod;
        }
        int x=(s-hs[i]*k)%mod;
        if(x<0) x+=mod;
        if(sum==x){
            cout << i;
            return 0;
        }
    }

    return 0;
}