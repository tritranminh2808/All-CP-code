#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int base=257;
unordered_map<int, vector <int> > adj;
unordered_map<int,bool>vst;
int hasht(string s){
    int ln=s.length();
    s='!'+s;
    int hashP=0;
    for(int i=1;i<=ln;++i)  hashP = (hashP*base+s[i]+1)%mod;
    return hashP;
}
int sech=0;
void dfs(int u){
    if(vst[u]||sech==-1) {
        sech=-1;
        return;
    }
    vst[u]=1;
    sech++;
    for(auto i:adj[u]){
        dfs(u);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        adj.clear();
        int n;cin>> n;
        vector <pair <int, int> > v; 
        while(n--){
            string a, b; cin >> a >> b;
            int k1=hasht(a),k2=hasht(b);
            adj[k1].push_back(k2);
            v.push_back({k1,k2});
        }
        bool chk=0;
        int cc=0;
        for(int i=0;i<n;i++){
            if(adj[v[i].second].empty()) continue;
            chk=1;
            vst.clear();
            dfs(v[i].second);
            sech=0;
            if(sech==-1) continue;
            if(sech%2==0) {
                cc=1;
                break;
            }
        }
        if(chk==0) cout << "Hieu\n";
        else if(sech==-1) cout << "Hoa\n";
        else if(cc==0) cout << "Quang\n";
        else cout << "Hieu\n";
    }
}