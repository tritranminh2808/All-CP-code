#include <bits/stdc++.h>
using namespace std;
struct song{
    int a,b,id;
};
struct hsinh{
    int c,d,k,id;
};
song s[100005];
hsinh p[100005];
bool cmp(song x, song y){
    return x.b<y.b;
}
bool cmp2(hsinh x, hsinh y){
    return x.c<y.c;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> s[i].a >> s[i].b;
        s[i].id=i;
    }
    cin >> m;
    for(int i=1;i<=m;i++) cin >> p[i].c > p[i].d >> p[i].k;
    sort(s+1,s+n+1,cmp);
    sort(p+1,p+m+1,cmp2);
    return 0;
}