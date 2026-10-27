#include <bits/stdc++.h>
using namespace std;
struct range{
	int l, r, id, lca;
};
range q[200001];
int c[200001];
int a[200001];
vector<int> adj[200001];
vector<int> pos[200001];
int depth[100001];
int tog[100001];
int bin[100001][17];
int dem[100001];
vector<int> e;
vector<bool> vst(100001, false);
void dfs(int i){
	vst[i] = true;
	e.push_back(i);
	for (auto j:adj[i]){
		if(!vst[j]){
			depth[j] = depth[i] + 1;
			bin[j][0] = i;
			dfs(j);
		}
	}
	e.push_back(i);
}
int lca(int u, int v){
	if(depth[u] < depth[v]){
		swap(u, v);
	}
	int diff = depth[u] - depth[v];
	for (int i = 0;i<17;++i){
		if(diff & (1<<i)){
			u = bin[u][i];
		}
	}
	if(u==v)return u;
	for (int i=16;i>=0;--i){
		if(bin[u][i]!=bin[v][i]){
			u = bin[u][i];
			v = bin[v][i];
		}
	}
	return bin[u][0];
}
int res[200001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, t;
	cin >> n >> t;
	map<int, int> mp;
	int tmp = 1;
	for (int i = 1;i<=n;++i){
		cin >> c[i];
		mp[c[i]] = -1;
	}
	for (auto &i:mp){
		i.second = tmp;
		tmp++;
	}
	for (int i = 1;i<=n;++i){
		c[i] = mp[c[i]];
	}
	for (int i = 1;i<n;++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for (int j = 1;j<17;++j){
		for (int i = 1;i<=n;++i){
			bin[i][j] = bin[bin[i][j-1]][j-1];
		}
	}
	int m = e.size()-1;
	for (int i = 0;i<=m;++i){
		pos[e[i]].push_back(i);
	}
	for (int i = 0;i<t;++i){
		int u, v;
		cin >> u >> v;
		if(pos[u][0] > pos[v][0])swap(u, v);
		int d = lca(u, v);
		if(d==u){
			q[i] = {pos[u][0], pos[v][0], i, -1};
		}else q[i] = {pos[u][1], pos[v][0], i, d};
	}
	m = e.size();
	int s = sqrt(m);
	sort(q, q+t, [&](range p, range q){
		if(p.l/s != q.l/s){
			return p.l/s < q.l/s;
		}else return p.r < q.r;
	});
	for (int i = 0;i<m;++i){
		a[i] = c[e[i]];
	}
	int l = 0, r = 0;
	int sol = 0;
	for (int i = q[0].l;i<=q[0].r;++i){
		tog[e[i]] ^= 1;
		if(tog[e[i]]==1){
			dem[a[i]]++;
			if(dem[a[i]]==1)sol++;
		}else{
			dem[a[i]]--;
			if(dem[a[i]]==0)sol--;
		}
	}
	if(q[0].lca!=-1){
		dem[c[q[0].lca]]++;
		if(dem[c[q[0].lca]]==1)sol++;
	}
	res[q[0].id] = sol;
	l = q[0].l, r = q[0].r;
	for (int i = 1;i<t;++i){
		if(q[i-1].lca!=-1){
			dem[c[q[i-1].lca]]--;
			if(dem[c[q[i-1].lca]]==0)sol--;
		}
		if(q[i].l < l){
			l--;
			while(q[i].l <= l){
				tog[e[l]]^=1;
				if(tog[e[l]]==1){
					dem[a[l]]++;
					if(dem[a[l]]==1)sol++;
				}else{
					dem[a[l]]--;
					if(dem[a[l]]==0)sol--;
				}
				l--;
			}
			l = q[i].l;
		}
		if(r<q[i].r){
			r++;
			while(r <= q[i].r){
				tog[e[r]]^=1;
				if(tog[e[r]]==1){
					dem[a[r]]++;
					if(dem[a[r]]==1)sol++;
				}else{
					dem[a[r]]--;
					if(dem[a[r]]==0)sol--;
				}
				r++;
			}
			r = q[i].r;
		}
		while(l<q[i].l){
			tog[e[l]]^=1;
			if(tog[e[l]]==1){
				dem[a[l]]++;
				if(dem[a[l]]==1)sol++;
			}else{
				dem[a[l]]--;
				if(dem[a[l]]==0)sol--;
			}
			l++;
		}
		while(q[i].r < r){
			tog[e[r]]^=1;
			if(tog[e[r]]==1){
				dem[a[r]]++;
				if(dem[a[r]]==1)sol++;
			}else{
				dem[a[r]]--;
				if(dem[a[r]]==0)sol--;
			}
			r--;
		}
		if(q[i].lca!=-1){
			dem[c[q[i].lca]]++;
			if(dem[c[q[i].lca]]==1){
				sol++;
			}
		}
		res[q[i].id] = sol;
	}
	for (int i = 0;i<t;++i){
		cout << res[i] << '\n';
	}
}