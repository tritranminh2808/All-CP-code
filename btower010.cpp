#include <bits/stdc++.h>
#define int long long
using namespace std;
struct sol{
	int l,r,h, pos;
	bool operator<(const sol &o) const{
		if(r!=o.r){
			return r < o.r;
		}else return l < o.l;
	}
};
struct range{
	int len, now, num, f;
};
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("BTOWER010.INP","r",stdin);
	freopen("BTOWER010.OUT","w",stdout);
	int n;
	cin >> n;
	vector<sol> a(n+1);
	for (int i = 1;i<=n;++i){
		cin >> a[i].l >> a[i].r >> a[i].h;
		a[i].pos = i;
	}
	sort(a.begin(), a.end());
	int j = 1;
	int bef = 0;
	vector<range> dp(1e6+2, {0, 0, 0});
	for (int i = 1;i<=1e6+1;++i){
		if(j<=n and i==a[j].r){
			int q = 0;
			while(j<=n and i==a[j].r){
				if(a[j].l!=a[j].r){
					int t = a[j].h + dp[a[j].l].len;
					if(t>dp[i].len){
						dp[i] = {t, a[j].pos, a[j].l, j};
					}
					if(dp[i-1].len > dp[i].len){
						dp[i] = dp[i-1];
					}
					q++;
					j++;
				}else{
					int tmp = a[j].r;
					int tt = 0;
					while(j<=n and a[j].r==tmp){
						tt+=a[j].h;
						j++;
					}
					j--;
					if(q==0){
						dp[i] = {tt + dp[i-1].len, a[j].pos, bef, j};
					}else dp[i] = {tt + dp[i].len, a[j].pos, dp[i].num, j};
					j++;
				}
			}
			bef = i;
		}else dp[i] = dp[i-1];
	}
	vector<int> res;
	int p = 1e6;
	while(dp[p].now!=0){
		res.push_back(dp[p].now);
		int it = dp[p].f-1;
		while(it >= 1 and a[dp[p].f].l==a[dp[p].f].r and a[it].l==a[dp[p].f].l and a[it].r==a[dp[p].f].r){
			res.push_back(a[it].pos);
			it--;
		}
		p = dp[p].num;
	}
	cout << dp.back().len << ' ' << res.size() << '\n';
	for (int i = res.size()-1;i>=0;--i){
		cout << res[i] << ' ';
	}
}
