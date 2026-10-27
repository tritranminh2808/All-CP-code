#include <bits/stdc++.h>
#define int int
using namespace std;
int main(){
	freopen("cellfill.inp","r",stdin);
	freopen("cellfill.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n; 
		vector <int> a;
		for(int i=0;i<n;i++) {
			int k; cin >> k;
			a.push_back(k);
		}
		stack<int> S;
		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			while (!S.empty() && S.top() > a[i]) S.pop(); 
			if (a[i] > 0 && (S.empty() || S.top() < a[i]))
			++res; 
			S.push(a[i]);
		}
		cout << res << "\n";
	}
	
	return 0;
}
