#include <bits/stdc++.h>
using namespace std;
int par[2000005],sz[2000005];
int n,m; 
int a[1005][1005];
int encode(int x, int y){
    return x*n+y;
}
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
bool vst[1005][1005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x=encode(i,j);
            par[x]=x;
            sz[x]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) 
    }

    return 0;
}