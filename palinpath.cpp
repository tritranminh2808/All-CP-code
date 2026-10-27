#include <bits/stdc++.h>
#define int long long
using namespace std;
#define pb push_back
int n,m;
vector <pair <int, char > > adj[1005];
int kc[1005][1005];
bool check(string s){
    string s1=s;
    reverse(s1.begin(),s1.end());
    return s1==s;
}
queue<pair <int,int > > q;
void run(){
    kc[1][2]=0;
    q.push({1,2});
    while(!q.empty()){
        pair <int,int> p=q.front();
        q.pop();
        for(auto i:adj[p.first]){
            for(auto j:adj[p.second]){
                if(i.second!=j.second) continue;
                if(kc[i.first][j.first]>kc[p.first][p.second]+2){
                    kc[i.first][j.first]=kc[p.first][p.second]+2;
                    q.push({i.first,j.first});
                }
            }
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) kc[i][j]=INT_MAX;
    }
    while(m--){
        int u,v;
        char c; cin >> u >> v >> c;
        adj[u].pb({v,c});
        adj[v].pb({u,c});
    }
    run();
    int ans=INT_MAX;
    for(int i=1;i<=n;i++) ans = min(ans, kc[i][i]);
    for(int i=1;i<=n;i++) for(auto j: adj[i]) ans = min(ans, kc[i][j.first]+1);
    cout << (ans==INT_MAX? -1: ans) ;
    return 0;
}