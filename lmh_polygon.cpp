#include <bits/stdc++.h>
using namespace std;
set<int> adj[100005];
int n,m;
vector <pair <int, int > >  pp;
struct pl{
	int c1,c2,c3;
};
vector <pl> trace;
int nxt[100005];
void bfs(){
	queue<int> q;
	for(int i=1;i<=n;i++) {
		if(adj[i].size()==2) q.push(i);
	}
	while(!q.empty()){
		int p=q.front();
//		cout << p;
		q.pop();
		if(adj[p].size()!=2) continue;
		int c1=-1,c2=-1;
		for(auto j:adj[p]){
			if(c1==-1) c1=j;
			else c2=j;
		}
		adj[c1].erase(p);
		adj[c2].erase(p);
		adj[p].clear();
		if(adj[c1].size()==2) q.push(c1);
		if(adj[c2].size()==2) q.push(c2);
		trace.push_back({p,c1,c2});
	}
}
bool ss(vector <int> a, vector <int> b){
	for(int i=0;i<n;i++){
		if(a[i]>b[i]) return true;
		else if(a[i]<b[i]) return false;
	}
	return true;
}
void find(){
	int c1=-1,c2=-1;
	for(int i=1;i<=n;i++){
		if(adj[i].size()>0){
			if(c1==-1) c1=i;
			else c2=i;
		}
	}
	nxt[c1]=c2;
	nxt[c2]=c1;
	for(int i=trace.size()-1;i>=0;--i){
		int x=trace[i].c1,a=trace[i].c2,b=trace[i].c3;
		if(nxt[a]==b){ // a-x-b
			nxt[a]=x;
			nxt[x]=b;
		}
		else {//b-x-a
			nxt[b]=x;
			nxt[x]=a;
		}
	}
	vector <int> sol;
	int cur=1;
	for(int i=0;i<n;i++){
		sol.push_back(cur);
		cur=nxt[cur];
	}
	int moc=0;
	for(int i=0;i<n;i++){
		if(sol[i]==1) {
			moc=i;
			break;
		}
	}
	vector <int> res;
	for(int i=moc;i<n;i++) res.push_back(sol[i]);
	for(int i=0;i<moc;i++) res.push_back(sol[i]);
	vector <int> res2=res;
	reverse(res2.begin()+1,res2.end());
	if(ss(res,res2)) for(auto i:res2) cout << i << " ";
	else for(auto i:res) cout << i << " ";
	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n+m;i++) {
		int u,v; cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	bfs();
	find();
//	cout << "\n";
//	for(auto i:pp)cout << i.first << " " << i.second << "\n";
	return 0;
} 
