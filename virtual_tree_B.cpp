#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
int n,q,m;
vector <int> adj[200005],adj2[200005];;
int dep[200005],high[200005],jump[200005][18];
int color[200005],num[200005],timer=0;
const int mod=998244353;
void dfs(int u,int v){
	num[u]=++timer;
	for(auto i:adj[u]){
		if(i==v) continue;
		dep[i]=dep[u]+1;
		jump[i][0]=u;
		dfs(i,u);
	
	}
}
void build(){
	for(int j=1;j<=17;j++) for(int i=1;i<=n;i++) jump[i][j]=jump[jump[i][j-1]][j-1];
}
int lca(int u, int v){
	if(dep[u]>dep[v]) swap(u,v);
	int dist=dep[v]-dep[u];
	for(int i=17;i>=0;i--){
		if(dist>= (1<<i)){
			dist-=(1<<i);
			v=jump[v][i];
		}
	}
	if(u==v) return u;
	for(int i=17;i>=0;--i){
		if(jump[v][i]==0||jump[u][i]==0) continue;
		if(jump[u][i]!=jump[v][i]){
			u=jump[u][i];
			v=jump[v][i];
		}
	}
	return jump[u][0];
}
bool cmp(int u, int v){
    return num[u]<num[v];
}
bool check(int u,int v){
    return lca(u,v)==u;
}
int xet=0;
ll dp[200005];
int colo[200005];
void dfss(int u, int v){
    // cout << u << " ";
    dp[u]=1;
    for(auto i:adj2[u]){
        if(i==v) continue;
        dfss(i,u);
        // cout << u << " " <<i << "\n";
        dp[u]=(dp[u]*(dp[i]+1))%mod;
    }
    if(colo[u]!=xet) dp[u]--;
}
ll sol=0;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	unordered_map<int,vector <int> > mp;
	for(int i=1;i<=n;i++) {
		cin >> color[i];
		mp[color[i]].push_back(i);
	}
	for(int i=1;i<n;i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0);
	build();
	// for(int i=1;i<=n;i++) cout << num[i] << " ";
    for(auto t:mp){
        vector <int> v=t.second;
        xet=t.first;
        // xay cay ao dang cap bum bum
        sort(v.begin(),v.end(),cmp);
        int m=v.size();
        for(int i=1;i<m;i++){
            v.push_back(lca(v[i],v[i-1]));
        }
        sort(v.begin(),v.end(),cmp);
        // for(auto i:v) cout << i << " ";
        // cout << endl;
        v.erase(unique(v.begin(),v.end()),v.end());
        unordered_map<int,int> idx;
        m=v.size();
        
        for(int i=0;i<m;i++) {
            idx[v[i]]=i+1;
            colo[i+1]=color[v[i]];
            adj2[i+1].clear();
        }
        stack<int> st;
        for(auto i:v){
            while(!st.empty()&&!check(st.top(),i)) st.pop();
            if(!st.empty()){
                adj2[idx[i]].push_back(idx[st.top()]);
                adj2[idx[st.top()]].push_back(idx[i]);
            }
            st.push(i);
        }  
        // cout << t.first << ":\n";
        dfss(1,0);
        // cout << xet;
        for(int i=1;i<=m;i++) {
            if(colo[i]==xet) sol=(sol+dp[i])%mod;
            else{
                sol=(sol+dp[i])%mod;
                for(auto j:adj2[i]) if(j>i) sol=(sol-dp[j]+mod)%mod;
            }
        }
    }
    cout << sol%mod;
	return 0;
}
