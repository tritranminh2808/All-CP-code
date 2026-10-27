#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n,m;
const int mod=998244353;
vector <pair <int, int > > pos[100005];
const int can=1999;
bool cmp(pair <int, int > a, pair <int, int > b){
    if(a.first+a.second==b.first+b.second) {
        if(a.first==b.first) return a.second < b.second;
        return a.first < b.first;
    }
    return a.first+a.second<b.first+b.second;
}
int ans=0;
int cal(vector <vector <int> > &v){
    vector <vector <int> > f(n+1,vector <int> (m+1,0));
    if(v[1][1]) return 0;
    f[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            if(v[i][j]||(i==1&&j==1)) continue;
            f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
        }
    }
    return f[n][m]%mod;
}
int power(int n,int k){
    int res=1;
    while(k){
        if(k%2==1) res=res*n%mod;
        k/=2;
        n=n*n%mod;
    }
    return res;
}
int gt[200005],tg[200005];
int ckn(int a, int k){
    if(k>a) return 0;
    return (gt[a]*tg[k]%mod*tg[a-k]%mod)%mod;
}
int cnt(int r1, int c1, int r2, int c2){
    if(r1>r2||c1>c2) return 0;
    return ckn(r2-r1+c2-c1,r2-r1);
}
void cok(){
    ans=0;
    cin >> n >> m;
    vector <vector <int> > a(n+1, vector <int> (m+1,0));
    vector <vector <int> > di(n+1, vector <int> (m+1,0));
    vector <vector <int> > den(n+2, vector <int> (m+2,0));
    vector <int> wout(n*m+1);
    vector <int> vallist;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> a[i][j];
            vallist.push_back(a[i][j]);
            pos[a[i][j]].clear();
        }
    }
    
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) pos[a[i][j]].push_back({i,j});
    
    di[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            if(i==1&&j==1) continue;
            di[i][j]=(di[i-1][j]+di[i][j-1])%mod;
        }
    }
    
    den[n][m]=1;
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--) {
            if(i==n&&j==m) continue;
            den[i][j]=(den[i+1][j]+den[i][j+1])%mod;
        }
    }

    sort(vallist.begin(),vallist.end());
    vallist.erase(unique(vallist.begin(),vallist.end()),vallist.end());
    
    for(auto x:vallist){
        sort(pos[x].begin(),pos[x].end(),cmp);
        if(pos[x].size()>can){
            vector <vector <int> > sech(n+1, vector <int> (m+1,0));
            for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]==x) sech[i][j]=1;
            ans=(ans+di[n][m]+mod-cal(sech)+mod)%mod;
            // ans%=mod;
            continue;
        }
        for(int i=0;i<pos[x].size();i++){
            int r=pos[x][i].first,c=pos[x][i].second;
            int w=di[r][c];
            int cur=0;
            for(int j=0;j<i;j++) {
                int r2=pos[x][j].first, c2=pos[x][j].second;
                int dem=cnt(r2,c2,r,c);
                cur=(cur+dem*wout[j]%mod)%mod;
            }
            wout[i]=(w-cur+mod)%mod;
        }
        for(int i=0;i<pos[x].size();i++) {
            int r=pos[x][i].first,c=pos[x][i].second;
            ans=(ans+wout[i]*den[r][c]%mod)%mod;
        }
    }
    cout << ans << "\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    gt[0]=1;
    for(int i=1;i<=100000;i++) gt[i]=gt[i-1]*i%mod;
    tg[100000]=power(gt[100000],mod-2);
    for(int i=100000-1;i>=0;i--) tg[i]=tg[i+1]*(i+1)%mod;
    cin >> t;
    while(t--){
        cok();
    }
    return 0;
}