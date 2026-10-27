#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
vector <int> adj[200005];
bool vst[200005];
int mau[200005];
vector <int> par[200005];
int dp[200005];
int cnttrang=0,cntden=0;
void to_mau(int u) {
	if(vst[u]) return;
	vst[u]=1;
	if(mau[u]==0) cnttrang++;
	else cntden++;
//	cout << u << "\n";
    for(auto i:adj[u]){
    	if(mau[i]==-1) mau[i]=1-mau[u];
    	else if(mau[i]==mau[u]){
    		cout << 0;
    		exit(0);
		}
		to_mau(i);
	}
}
long long sol=0;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    m=n-1;
    for(int i=1;i<=200000;i++) mau[i]=-1;
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
	}
    mau[1]=1;
//    cout << endl;
    to_mau(1);
//    for(int i=1;i<=n;i++) cout  << mau[i] << " ";
    for(int i=1;i<=n;++i){
    	if(mau[i]==0) sol+=cntden-adj[i].size();
		else sol+=cnttrang-adj[i].size();
//		cout << i << " " << sol << "\n";
	}
	cout << sol/2;
    return 0;
}

