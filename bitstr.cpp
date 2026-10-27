#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4.2,popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wformat-security"
using namespace std;
bool a[1000006];
int pre[1000005],pre2[1000005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;cin >> s;
    int m; cin >> m;
    int n=s.length();
    bool ch0=0,ch1=0;
    int sol0=0,sol1=0;
    for(int i=1;i<=n;i++) a[i]=s[i-1]-'0';
    for(int i=1;i<=n-m+1;++i){
        pre[i]+=pre[i-1];
        if(a[i]!=0&&pre[i]%2==0){
            pre[i]++;
            sol0++;
            pre[i+m]--;
        }
        else if(a[i]==0&&pre[i]%2==1){
            pre[i]++;
            sol0++;
            pre[i+m]--;
        }
        pre2[i]+=pre2[i-1];
        if(a[i]&&pre2[i]%2!=0){
            pre2[i]++;
            sol1++;
            pre2[i+m]--;
        }
        else if(!a[i]&&pre2[i]%2==0){
            pre2[i]++;
            sol1++;
            pre2[i+m]--;
        }
    }
    for(int i=n-m+2;i<=n;i++){
        pre[i]+=pre[i-1];
        if((a[i]!=0&&pre[i]%2==0)||(a[i]==0&&pre[i]%2==1)) {
            ch0=1;
            break;
        }
    }
    for(int i=n-m+2;i<=n;i++){
        pre2[i]+=pre2[i-1];
        if((!a[i]&&pre2[i]%2==0)||(a[i]&&pre2[i]%2==1)) {
            ch1=1;
            break;
        }
    }
    if(ch0&&ch1) cout << -1;
    else if(ch0) cout << sol1;
    else if(ch1) cout << sol0;
    else cout << min(sol0,sol1);
}
