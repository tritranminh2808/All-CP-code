#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,dp[100005][2],h[100005];
vector<int> par[100005];
void dfs(int u,int pu)
{
    
	dp[u][1]=h[u];
    for(auto v:par[u]) if(v!=pu) dfs(v,u);
    for(auto v:par[u])
    {
        if(v!=pu)
        {
            dp[u][0]+=max(dp[v][0],dp[v][1]);
            dp[u][1]+=dp[v][0];
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int b,i=1;i<=n;++i)
    {
        cin>>b>>h[i];
        par[i].push_back(b);
        par[b].push_back(i);
    }
    dfs(1,0);
    cout << max(dp[1][0],dp[1][1]);
}

