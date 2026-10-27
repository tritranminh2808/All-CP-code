#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct luu{
	ll v, t;
};
bool cmp(luu a, luu b){
	return a.v<b.v;
}
bool cmp1(luu a, luu b){
	return a.t<b.t;
}
int main(){
	long long n, k;
	cin >> n >> k;
	vector<luu> a(n);
	long long tong = 0;
	for (ll i = 0;i<n;++i){
		cin >> a[i].v;
		tong += a[i].v;
		a[i].t = i;
	}
	sort(a.begin(),a.end(), cmp);
	if(tong<k){
		cout << -1;
		return 0;
	}
	else if (tong==k){
		sort(a.begin(),a.end(), cmp1);
		for (ll i = 0;i<n;++i){
			cout << a[i].v << " ";
		}
	}else{
		ll t = 0;
		for (ll i = 0;i<n;++i){
			if(i==0) t += a[i].v * (n-i);
			
			else t+= (a[i].v - a[i-1].v) * (n-i);
			
			if(t==k){
				for (ll j = i;j<n;++j)	a[j].v = a[i].v;
				sort(a.begin(), a.end(), cmp1);
				for (ll j = 0;j<n;++j) cout << a[j].v << " ";
				return 0;
			}
			else if(t>k){
				ll du = t - k;
				ll time = du/(n-i);
				du = du%(n-i);
				ll tmp = a[i].v;
				for (ll j = i;j<n;++j){
					a[j].v = tmp;
					a[j].v -= time;
					if(du>0){
						a[j].v-=1;
						du--;
					}
				}
				sort(a.begin(), a.end(), cmp1);
				for (ll j = 0;j<n;++j) cout << a[j].v << " ";
				return 0;
			}
		}
	}
}
