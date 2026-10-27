#include <bits/stdc++.h>
#define int long long
using namespace std;
struct pl{
    int val, cnt;
};
int st[51][40005];
int a[10005],n,k;
int dp[51][100005];
const int mod=1e9+7;
vector <int> b;
void nen(){
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++) b.push_back(a[i]);
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int i=0;i<b.size();i++) mp[b[i]]=i+1;
    for(int i=1;i<=n;i++) a[i]=mp[a[i]];
}
void update(int x, int id, int l, int r, int u, int v){
    if(u<l||u>r) return;
    if(l==r){
        st[x][id]=(st[x][id]+v)%mod;
        return;
    }
    int mid=(l+r)/2;
    update(x,id*2,l,mid,u,v);
    update(x,id*2+1,mid+1,r,u,v);
    st[x][id]=(st[x][id*2]+st[x][id*2+1])%mod;
}
int find(int x, int id, int l, int r, int lf, int rt){
    if(lf>r||rt<l) return 0;
    if(lf<=l&&rt>=r) return st[x][id]%mod;
    int mid=(l+r)/2;
    return (find(x,id*2,l,mid,lf,rt)+find(x,id*2+1,mid+1,r,lf,rt))%mod;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    nen();
    // for(int i=1;i<=n;i++) cout << a[i] << " ";
    // cout << endl;
    int maxx=b.size();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j==1){
                dp[j][i]=1;
                update(j,1,1,maxx,a[i],1);
                continue;
            }
            dp[j][i]=find(j-1,1,1,maxx,1,a[i]-1)%mod;
            update(j,1,1,maxx,a[i],dp[j][i]);
        }
    }
    int sol=0;
    /*for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++) cout << dp[i][j] << " ";
        cout << "\n";
    }*/
    for(int i=1;i<=n;i++) sol=(sol+dp[k][i])%mod;
    cout << sol;
    return 0;
}
