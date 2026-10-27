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
    return x.a<y.a;
}
bool cmp2(hsinh x, hsinh y){
    return x.c<y.c;
}
int cnt[100005],ans[100005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> s[i].a >> s[i].b;
        s[i].id=i;
    }
    cin >> m;
    for(int i=1;i<=m;i++) {
        cin >> p[i].c >> p[i].d >> p[i].k;
        p[i].id=i;
        cnt[i]=p[i].k;
    }
    sort(s+1,s+n+1,cmp);
    sort(p+1,p+m+1,cmp2);
    set<pair<int, int > > st;
    int j=1;
    for(int i=1;i<=n;i++){
        while(j<=m&&p[j].c<=s[i].a){
            st.insert({p[j].d,p[j].id});
            j++;
        }
        auto it=st.lower_bound({s[i].b,-1});
        if(it==st.end()){
            cout << "NO";
            return 0;
        }
        ans[s[i].id]=it->second;
        cnt[it->second]--;
        if(cnt[it->second]==0) st.erase(it);
    }
    cout << "YES\n";
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    return 0;
}