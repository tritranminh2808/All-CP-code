#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int f[(1<<20)+5],h[(1<<20)+5],n,m;
string a[1005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    int mask=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            mask=0;
            for(int k=0;k<m;++k){
                if(a[i][k]!=a[j][k]) mask|=(1<<k);
            }
            f[mask]++;
        }
    }
    int sz=(1<<m)-1;
    for(int i=0;i<(1<<m);i++) h[i]=f[i];
    for(int i=0;i<m;i++)
        for(int mask=0;mask<=sz;mask++)
            if(mask&(1<<i)) h[mask]+=h[mask^(1<<i)];
    int ans=m;
    for(int mask=0;mask<=sz;mask++){
        if(h[sz^mask]==0){
            int c=__builtin_popcount(mask);
            if(c<ans) ans=c;
        }
    }
    cout<<ans;
    return 0;
}