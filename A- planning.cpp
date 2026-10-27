#include <bits/stdc++.h>
using namespace std;
pair <int,int> pos[1000005];
bool cmp(pair <int, int > a, pair <int, int > b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
bool check(int k){
    vector <pair <int, int > > v;
    for(int i=0;i<k;i++) v.push_back(pos[i]);
    sort(v.begin(),v.end(),cmp);
    for(int i=1;i<v.size();++i){
        if(v[i].first>=v[i-1].first&&v[i].second>=v[i-1].second) continue;
        return false;
    }
    return true;
}
void solce(){
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x; cin >> x;
            pos[x]={i,j};
        }
    }
    int l=1,r=n*m;
    int sol=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) {
            l=mid+1;
            sol=mid;
        }
        else r=mid-1;
    }
    cout << sol << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solce();
    }
    return 0;
}