#include <bits/stdc++.h>
using namespace std;
struct pl{
    int a,b,c;
};
pl v[1000005];
int n;
bool cmp(pl x, pl y){
    return x.a < y.a;
}
int st[1000005];
void update(int i, int v){
    for(;i<=n;i+=i&-i) st[i]=min(st[i],v);
}
int find(int i){
    int s=INT_MAX;
    for(;i>0;i-=i&-i) s=min(s,st[i]);
    return s;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
        int u; cin >> u;
        v[u].a=i;
    }
    for(int i=1;i<=n;i++) {
        int u; cin >> u;
        v[u].b=i;
    }
    for(int i=1;i<=n;i++) {
        int u; cin >> u;
        v[u].c=i;
    }
    sort(v+1,v+n+1,cmp);
    int sol=0;
    for(int i=1;i<=n;++i) st[i]=INT_MAX;
    for(int i=1;i<=n;i++){
        int k=find(v[i].b-1);
        if(k>v[i].c) {
            // cout << i << " ";
            sol++;
        }
        update(v[i].b,v[i].c);
    }
    cout << sol;
    return 0;
}