#include <bits/stdc++.h>
using namespace std;
int pa[100005],pb[100005],n;
int ca[100005],cb[100005];
vector <int > a, b;
void dfs1(int u){
    a.push_back(u);
    if(ca[u]) dfs1(ca[u]);
}
void dfs2(int u){
    b.push_back(u);
    if(cb[u]) dfs2(cb[u]);
}
int v[1000005];
int main(){
    freopen("comseq.inp","r",stdin);
    freopen("comseq.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int ra=0,rb=0;
    for(int i=1;i<=n;i++) {
        cin >> pa[i] >> pb[i];
        ca[pa[i]]=i;
        cb[pb[i]]=i;
        if(pa[i]==-1) ra=i;
        if(pb[i]==-1) rb=i;
    }
    dfs1(ra);
    dfs2(rb);
    for(int i=0;i<n;i++){
        // cin >> b[i];
        v[b[i]]=i;
    }
    vector <int> arr(a.size());
    for(int i=0;i<n;i++) arr[i]=v[a[i]];
    // cin >> n;
    unordered_map<int,int> mp;
    vector<int> dp;
    for (int x:arr) {
        // cout << x;
        auto it=lower_bound(dp.begin(), dp.end(), x);
        if (it==dp.end()) dp.push_back(x);
        else *it=x;
	}
    cout << dp.size();
    return 0;
}