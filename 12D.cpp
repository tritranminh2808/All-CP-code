#include <bits/stdc++.h>
using namespace std;
struct pl{
    int a,b,c;
};
pl v[1000005];
int n;
bool cmp(pl x, pl y){
    return x.a > y.a;
}
int st[1000005];
int sz=0;
void update(int i, int v){
    for(;i<=sz+1;i+=i&-i) st[i]=max(st[i],v);
}
int find(int i){
    int s=0;
    for(;i>0;i-=i&-i) s=max(s,st[i]);
    return s;
}
vector<int> bb;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i].a;
    for(int i=1;i<=n;i++) cin >> v[i].b;
    for(int i=1;i<=n;i++) {
        cin >> v[i].c;
        bb.push_back(v[i].a);
        bb.push_back(v[i].b);
        bb.push_back(v[i].c);
    }
    sort(bb.begin(),bb.end());
    bb.erase(unique(bb.begin(),bb.end()),bb.end());
    for(int i=1;i<=n;i++){
        v[i].a=lower_bound(bb.begin(),bb.end(),v[i].a)-bb.begin()+1;
        v[i].b=lower_bound(bb.begin(),bb.end(),v[i].b)-bb.begin()+1;
        v[i].c=lower_bound(bb.begin(),bb.end(),v[i].c)-bb.begin()+1;
        // cout << v[i].a << " " << v[i].b << " " << v[i].c << "\n";
    }
    sort(v+1,v+n+1,cmp);
    int sol=0;
    sz=bb.size()+1;
    // cout << sz;
    // for(int i=1;i<=n;++i) st[i]=INT_MAX;
    int i=1;
    while(i<=n){
        int j=0;
        for(j=i+1;j<=n;j++) {
            if(v[j].a!=v[i].a) break;
        }
        for(int k=i;k<j;k++) {
            if(find(sz-v[k].b-1)>v[k].c) sol++;
        }
        for(int k=i;k<j;k++) update(sz-v[k].b,v[k].c);
        i=j;
    }
    cout << sol;
    return 0;
}