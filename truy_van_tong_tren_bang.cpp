#include <bits/stdc++.h>
using namespace std;
int n,m,q;
void sub3(){
    vector <int> a(m+1);
    vector <long long > pre(m+1);
    for(int i=1;i<=m;i++) cin >> a[i];
    for(int i=1;i<=m;i++) pre[i]=pre[i-1]+a[i];
    while(q--){
        int x,y,u,v; cin >> x >> y >> u >> v;
        cout << pre[v]-pre[y-1] << "\n";
    }
    exit(0);
}
int encode(int x, int y){
    return (x-1)*m+y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q ;
    
    if(n==1) sub3();
    if(n==5){

    }
    vector <vector <int> > a(n+1,vector (m+1,0));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];
    if(n*m<=3005&&q<=1005){
        while(q--){
            int x,y,u,v; cin >> x >> y >> u >> v;
            vector < vector <long long > > f(n+1,vector <long long > (m+1,1e18));
            f[x][y]=a[x][y];
            for(int i=x;i<=u;i++)    for(int j=y;j<=v;j++){if(i==x&&j==y) continue;f[i][j]=min(f[i][j-1],f[i-1][j])+a[i][j];}
            cout << f[u][v] << "\n";
        }
        return 0;
    }
    else if(n*m<=10005){
        int f[10005][10005];
        for(int i=0;i<=10000;i++) for(int j=0;j<=10000;j++) f[i][j]=1e9+9;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int x=encode(i,j);
                f[x][x]=a[i][j];
                for(int r=i;r<=n;++r){
                    for(int c=j;c<=m;c++){
                        if(r==i&&c==j) continue;
                        f[x][encode(r,c)]=min(f[x][encode(max(r-1,1),c)],f[x][encode(r,max(c-1,1))])+a[r][c];
                    }
                }
            }
        }
        while(q--){
            int x,y,u,v; cin >> x >> y >> u >> v;
            cout << f[encode(x,y)][encode(u,v)] << "\n";
        }
    }
    return 0;
}