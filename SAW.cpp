#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n+1);
	a[0] = 0;
	long long b[k];
	for (long long i = 1;i<=n;++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<long long> c(n+1, 0);
	for (long long i = 0;i<=n;++i){
		c[0] +=a[i];
	}
	for (long long i = 1;i<=n;++i){
		c[i] = c[i-1]-(a[i]-a[i-1])*(n-i+1);
	}
	sort(c.begin(),c.end());
	sort(a.begin(),a.end(), cmp);
	for (long long i = 0;i<k;++i){
		cin >> b[i];
		auto p = lower_bound(c.begin(), c.end(), b[i]);
		if(*p == b[i]){
			long long t = p-c.begin();
			cout << a[t] << " ";
		}else{
			long long t = p-c.begin();
			long long res = a[t];
			long long j = c[t];
			while(j>=b[i]){
				res++;
				j-=t;
				if(res==a[t-1]){
					t--;
				}
			}
			cout << res-1 << " "  ;
		}
	}
}
