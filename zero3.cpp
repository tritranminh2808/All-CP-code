#include <bits/stdc++.h>
using namespace std;
long long f[(const int) 4e6+5],pre[505],ff[4000005];
const int cu=2e6;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int x; cin>> x;
        pre[i]=pre[i-1]+x;
    }
    long long sol=0;
    for(int j=1;j<=n;j++){
        for(int p=1;p<=n;p++){
            for(int q=p;q<=n;q++) f[pre[j-1]-pre[q]+pre[p-1]+cu]++;
        }
        for(int u=1;u<=n;u++) for(int v=u;v<=n;v++) sol+=f[pre[j]+pre[v]-pre[u-1]+cu];
    }
    for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) ff[pre[j]-pre[i-1]+cu]++;
    for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) sol-=3*ff[-2*pre[j]+2*pre[i-1]+cu];
    sol+=2*ff[cu];
    cout << sol/6;
    return 0;
}