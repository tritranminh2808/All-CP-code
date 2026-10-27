#include <bits/stdc++.h>
using namespace std;
int pre[500005];
bool cmp(pair <int,int > a, pair <int, int > b){
    if(a.first==b.first) return a.second<b.second;
    return a.first <b.first;
}
vector <int> gt[500005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin >> n >>k;
    vector <int> a(n+1);
    // cout << n;
    set <int> tt;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]!=k) tt.insert(a[i]);
        pre[i]=pre[i-1];
        if(a[i]==k) pre[i]++;
        gt[a[i]].push_back(i);
    }
    int sol=0;
    for(auto i:tt){
        vector <int> x;
        x.push_back(-pre[gt[i][0]]);
        x.push_back(1);
        for(int j=1;j<gt[i].size();j++){
            x.push_back(-pre[gt[i][j]]+pre[gt[i][j-1]]);
            x.push_back(1);
        }
        int maxx=-INT_MAX,cur=0;
        for(auto j:x){
            cur=max(j,cur+j);
            maxx=max(maxx,cur);
        }
        sol=max(sol,maxx);
    }
    cout << sol+pre[n];
    return 0;
}