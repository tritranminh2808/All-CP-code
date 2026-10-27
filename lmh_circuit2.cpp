#include <bits/stdc++.h>
//#define int long long
using namespace std;
vector <int> sol;
bool vst[100005],cc[100005];
bool check=false;
int moc=-1,z;
vector <int> adj[100005];
void dfs(int i){
	if(vst[i]) {
		moc=i;
		return;
	}
	vst[i]=1;
	for(auto j: adj[i]) dfs(j);
}
string ss="";
string trace(int z,string ss){
//	cout << z << "\n";
	if(cc[z]) return ss;
	cc[z]=1;
	for(auto i:adj[z]) trace(i,ss+char('0'+i));
	return ss;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin >> n >> m;
	map<pair<int, int> , int> cung;
	for(int i=0;i<m;i++){
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
		cung[{u,v}]=i+1;
	}
	
	dfs(1);
	if(moc==-1){
		cout << "NO";
		return 0;
	}
	z=moc;
	string str=trace(z,ss);
	for(int i=0;i<str.length();i++) sol.push_back(int(str[i]));
	for(auto i: sol) cout << i << " ";
//	cout << trace(z,ss);
//	cout << moc;
}
