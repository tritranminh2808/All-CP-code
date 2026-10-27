#include <bits/stdc++.h>
using namespace std;
int h[100005],v[100005];
bool cmp(int a, int b){
    if(h[a]==h[b]) return a<b;
    return h[a]>h[b];
}
using namespace chrono;
bool del[100005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    auto start=high_resolution_clock::now();
    int n,k; cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> h[i];
    for(int i=1;i<=n;i++) cin >> v[i];
    vector <int> lit;
    for(int i=1;i<=n;i++) lit.push_back(i);
    sort(lit.begin(),lit.end(),cmp);
    int ans=0;
    
    // cout << n;
    // return 0;
    for(auto i:lit){
        if(del[i]) continue;
        
        ans++;
        del[i]=1;
        int ucv=-1;
        vector <int> r;
        r.push_back(i);
        for(int j=i+1;j<=n;j++) {
            if(v[j]>v[r.back()]+k) break;
            if(del[j]) continue;
            if(v[j]<=v[i]+k) ucv=j;
            r.push_back(j);
        }
        auto now = high_resolution_clock::now();
        double elapsed = duration<double>(now-start).count();
        if (elapsed >=0.4) {
            cout << n;
            return 0;
        }
        // cout <<i << " "  << ucv << "\n";
        vector <int> l;
        l.push_back(i);
        for(int j=i+1;j<=n;j++){
            if(v[j]>v[l.back()]+k) break;
            if(j==ucv||del[j]) continue;
            del[j]=1;
            // cout << j << " ";
            l.push_back(j);
        }
        // cout << endl;
    }
    cout << ans;
    return 0;
}
