#include <bits/stdc++.h>
// #define int long long
using namespace std;
int n,m;
set <int> adj[100005];
int num[100005],low[100005],bel[100005],sz[100005],dem[100005];
int cnt=0,cc=0;
bool del[100005];
stack <int> st;
int cntcomp=0;
void dfs(int u){
    num[u]=low[u]=++cnt;
    st.push(u);
    for(auto i:adj[u]){
        if(!del[i]){
            if(num[i])low[u]=min(low[u],num[i]);
            else {
                dfs(i);
                low[u]=min(low[i],low[u]);
            }
        }
    }
    if(low[u]==num[u]){
        int v;
        ++cntcomp;
        do{
            v=st.top();
            st.pop();
            del[v]=1;
        }while(v!=u);
    }
}
char a[105][105];
void reset(int n){
    while(!st.empty()) st.pop();
    for(int i=1;i<=n;i++){
        del[i]=0;
        num[i]=0;
        low[i]=0;
        adj[i].clear();
    }
    cnt=0;
    cntcomp=0;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n;
        reset(n);
        for(int i=1;i<=n;i++){
            string s; cin >> s;
            for(int j=0;j<n;j++) {
                if(s[j]=='Y') adj[i].insert(j+1);
            }
        }
        for(int i=1;i<=n;i++) if(!num[i]) dfs(i);
        cout << cntcomp << "\n";
    }
}