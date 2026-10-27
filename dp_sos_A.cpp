#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[(1<<20)+1];
ll a[1000005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ty; cin >> ty;
    int n; cin>> n; 
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        dp[i]=a[i];
    }
    int cnt=0;
    while((1<<cnt)<=n) cnt++; 
    for(int j=0;j<cnt;j++){
        for(int mask=0;mask<(1<<cnt);++mask){
            if(ty==1){
                 if((mask&(1<<j))) dp[mask]+=dp[mask^(1<<j)];
            }
            else if(ty==2) {

;                if(!(mask&(1<<j))) dp[mask]+=dp[mask^(1<<j)];
            }
        }
    }
    int sz=__lg(n)+1;
    for(int i=1;i<(1<<sz);i++) cout << dp[i] <<  " ";
    return 0;
}