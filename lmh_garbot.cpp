#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
int a[100005],b[100005],m,n,pre[100005],nxt[100005],timer[100005];
bool ch[100005];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int l=0,r=2e18;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        int id=1;
        for(int i=1;i<=n;i++){
            if(id>m) break;
            if(a[i]<=b[id]){
                while(id<=m&&a[i]+mid>=b[id]) id++;
            }
            else{
                int d=a[i]-b[id];
                if(d>mid) break;
                int t1=mid-2*d, t2=(mid-d)/2;
                int lim=a[i]+max(t1,t2);
                while(id<=m&& b[id]<=lim) id++;
            }
        }
        if(id>m){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout << ans;
    return 0;
}