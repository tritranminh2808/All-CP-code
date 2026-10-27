#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[100005],b[100005];
int mu[12]={10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000};
int scs(int a){
    int t=0;
    while(a>0){
        t++;
        a/=10;
    }
    return t;
}
void bruteforce(){
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) {
            int s=a[i];
            s*=mu[scs(b[j])-1];
            s+=b[j];
            if(s%k==0) res++;
        }
    }
    cout << res;
}
int mod[18][100005];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    if(n<=2000){
        bruteforce();
        return 0;   
    }
    for(int i=1;i<=n;i++) {
        int x=(k-b[i])%k;
        if(x<0)x+=k;
        mod[scs(b[i])][x]++;
        // cout << scs(b[i]) << " " << x << "\n";
    }
    int sol=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++) sol+=mod[j][a[i]*mu[j-1]%k];
        // cout << sol << "\n";
    }
    cout << sol;
    return 0;
}