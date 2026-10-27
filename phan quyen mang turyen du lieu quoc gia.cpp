#include <bits/stdc++.h>
#define ll long long

using namespace std;

using namespace std;
ll n,m,k;
vector <int > adj[100005];
bool vst[100005];
void bfs(int u){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		if(vst[p]) continue;
		vst[p]=1;
		for(auto i:adj[p]) q.push(i);
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k; cin >> n >> m >> k;
	int cnt=0;
	while(m--){
		int a,b,c; cin >> a >> b >> c;
		if(c==0) adj[a].push_back(b);
		else cnt++;
	}
	bfs(1);
	if(vst[n]) cout << "NO";
	else {
		cout << "YES\n";
		for(int i=0;i<cnt;i++) cout << 1 << " ";
	}
	return 0;
}
