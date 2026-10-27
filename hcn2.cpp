#include <bits/stdc++.h>
#define int long long
using namespace std;

int querymax(const vector<vector<int>> &st, int l, int r) {
	int len = r - l + 1;
	int p = __lg(len);
	return max(st[p][l], st[p][r - (1ll << p) + 1]);
}

int querymin(const vector<vector<int>> &st, int l, int r) {
	int len = r - l + 1;
	int p = __lg(len);
	return min(st[p][l], st[p][r - (1ll << p) + 1]);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	vector<pair<int,int>> pts(k);
	vector<vector<int>> rws(n+1);
	for(int i = 0; i < k; i++){
		int r, c; cin >> r >> c;
		pts[i] = {r, c};
		rws[r].push_back(c);
	}
	for(int i = 1; i <= n; i++) 
		sort(rws[i].begin(), rws[i].end());
	int sol = 0;
	for(auto p : pts){
		int cr = p.first, cc = p.second;
		vector<int> xx(n+1), yy(n+1);
		for(int i = 1; i <= n; i++){
			if(!rws[i].empty()){
				int l = 0, r = m + 1;
				auto &v = rws[i];
				int pos = lower_bound(v.begin(), v.end(), cc) - v.begin();
				if(i == cr){
					if(pos > 0) l = v[pos-1];
					if(pos+1 < v.size()) r = v[pos+1];
				}else{
					if(pos > 0) l = v[pos-1];
					if(pos < v.size()) r = v[pos];
				}
				xx[i] = l + 1;
				yy[i] = r - 1;
			}else{
				xx[i] = 1;
				yy[i] = m;
			}
		}
		int ln = floor(log2(n)) + 1;
		vector<vector<int>> stmax(ln, vector<int>(n+1));
		vector<vector<int>> stmin(ln, vector<int>(n+1));
		for(int i = 1; i <= n; i++){
			stmax[0][i] = xx[i];
			stmin[0][i] = yy[i];
		}
		for(int j = 1; j < ln; j++){
			for(int i = 1; i + (1ll << j) - 1 <= n; i++){
				stmax[j][i] = max(stmax[j-1][i], stmax[j-1][i + (1ll << (j-1))]);
				stmin[j][i] = min(stmin[j-1][i], stmin[j-1][i + (1ll << (j-1))]);
			}
		}
		int cur = 0;
		for(int a = 1; a <= cr; a++){
			int lo = cr, hi = n, b = cr - 1;
			while(lo <= hi){
				int mid = (lo + hi) / 2;
				int lq = querymax(stmax, a, mid);
				int rq = querymin(stmin, a, mid);
				if(rq >= lq){
					b = mid;
					lo = mid + 1;
				}else{
					hi = mid - 1;
				}
			}
			if(b >= cr){
				int lq = querymax(stmax, a, b);
				int rq = querymin(stmin, a, b);
				int w = rq - lq + 1, h = b - a + 1;
				cur = max(cur, w * h);
			}
		}
		sol = max(sol, cur);
	}
	cout << sol;
	return 0;
}

