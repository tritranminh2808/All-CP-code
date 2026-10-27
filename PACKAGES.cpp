#include <bits/stdc++.h>
using namespace std;
void xu_li()
{
	long long n,k; cin >> n >> k;
	multiset <int> set;
	for(int i=0;i<n;i++) {
		int p;cin >> p;
		auto it=set.lower_bound(p);
		if(it!=set.end()){
			set.insert(*it-p);
			set.erase(it);
		}
		else set.insert(k-p);
	}
	cout << set.size() << "\n";
}

int  main(){
	freopen("packages.inp","r",stdin);
	freopen("packages.out","w",stdout);
	long long t;
	cin >> t;
	while(t--)xu_li();
	return 0;
}
