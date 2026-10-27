#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4.2,popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wformat-security"
using namespace std;
int n,m;
int a[45][45];
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
int g[4];
bool vst[45][45];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for( int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];
    int sol=INT_MAX,gtri=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int tt=0,ch=0;
            for(int p=1;p<=n;p++){
                for(int q=1;q<=m;q++){
                    if(p==i&&q==j) continue;
                    int curx=i,cury=j,dem=0;
                    bool ok=0;
                    memset(vst,0,sizeof(vst));
                    while(1){
                        if(vst[curx][cury]) break;
                        vst[curx][cury]=1;
                        if(curx==p&&cury==q) {
                            ok=1;
                            break;
                        }
                        dem++;
                        for(int x=0;x<4;x++){
                            g[x]=INT_MAX;
                            int newx=curx+dx[x],newy=cury+dy[x];
                            if(newx>n||newx<1||newy>m||newy<1) continue;
                            g[x]=a[newx][newy];
                        }
                        int minc=INT_MAX,cnt=1,h1=0,h2=0;
                        vector <int> gg;
                        for(int o=0;o<4;o++) {
                            int l=abs(g[o]-a[p][q]);
                            if(l<minc){
                                minc=l;cnt=1;
                                gg.clear();
                                gg.push_back(o);
                                h1=curx+dx[o],h2=cury+dy[o];
                            }
                            else if(l==minc) {
                                cnt++;
                                gg.push_back(o);
                            }
                        }
                        if(cnt==1){
                            curx=h1;cury=h2;
                            continue;
                        }
                        int minn=INT_MAX,cn=1,h3=0,h4=0;
                        for(auto o:gg){
                            int l=abs(g[o]-a[curx][cury]);
                            if(l<minn){
                                minn=l;cn=1;
                                h3=curx+dx[o],h4=cury+dy[o];
                            }
                            else if(l==minn) cn++;
                        }
                        if(cn>1) break;
                        curx=h3,cury=h4;
                    }
                    if(!ok) {
                        ch=1;
                        break;
                    }
                    // cout << i << " " << j << ": " << p << " " << q << " " << dem << "\n";
                    tt=max(tt,dem);
                }
                if(ch) break;
            }
            if(tt<sol&&!ch){
                sol=tt;
                gtri=a[i][j];
            }
        }
    }
    if(sol==INT_MAX){
        cout << -1;
        return 0;
    }
    cout << gtri << " " << sol;
    return 0;
}