#include <bits/stdc++.h>
using namespace std;
// #define int long long
int n;
int a[200005];
vector <int> uoc[200005];
void txl(){
    for(int i=1;i<=200000;i++){
        for(int j=i;j<=200000;j+=i) uoc[j].push_back(i);
    }
}
struct pl{
    int id, x, ch;
};
vector <int> pos[200005];
vector <pl> s[100005];
int res[200005],cnt[200005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; //cin >> q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    txl();
    for(int i=1;i<=q;i++){
        int l, r, w; cin >> l >> r >> w;
        s[l-1].push_back({i,w,0});
        s[r].push_back({i,w,1});
        for(auto j:uoc[w]){
            if(j==w) continue;
            res[i]+=upper_bound(pos[j].begin(),pos[j].end(),r)-lower_bound(pos[j].begin(),pos[j].end(),l);
        }
    }
    for(int i=1;i<=n;i++){
        for(auto j:uoc[a[i]]) cnt[j]++;
        for(auto j:s[i]){
            if(j.ch==0) res[j.id]-=cnt[j.x];
            else res[j.id]+=cnt[j.x];
        }
    }
    for(int i=1;i<=q;i++) cout << res[i] << "\n";
    return 0;
}