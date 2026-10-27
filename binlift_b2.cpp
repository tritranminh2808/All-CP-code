#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k; int a[400005],nxt[400004];
int jump[25][400005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) a[i+n]=a[i];
    int goc=n;
    n=n*2;
    int idx=1,s=0;
    for(int i=1;i<=n;i++){
        while(idx<=n&&s+a[idx]<=k) {
            
            s+=a[idx];
            idx++;
        }
        nxt[i]=idx;
        s-=a[i];
        if(idx<i+1) idx=i+1;
    }
    nxt[n+1]=n+1;
    for(int i=1;i<=n+1;i++) jump[0][i]=nxt[i];
    for(int j=1;j<23;j++) for(int i=1;i<=n+1;i++) jump[j][i]=jump[j-1][jump[j-1][i] ];
    int ans=goc;
    for(int i=1;i<=goc;i++){
        // int tgt=i+goc;
        int cur=i;
        if(jump[0][cur]>=i+goc){ 
            ans=1; 
            continue; 
        }
        int cnt=0;
        for(int j=22;j>=0;j--) if(jump[j][cur]<i+goc){
            cur=jump[j][cur];
            cnt+=(1<<j);
        }
        cnt++;
        ans=min(ans,cnt);
    }
    cout<<ans<<"\n";
	return 0;
}
