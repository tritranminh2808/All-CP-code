#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("abm,avx2,bmi,bmi2")

using namespace std;
bool cmp( pair<int,int> a, pair<int,int> b){
	return a.first< b.first;
	
}
int val=0;
signed main() {
	freopen("peach.inp","r",stdin);
	freopen("peach.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<pair<int, int>> p(n); 
    for (int i = 0; i < n; ++i) cin >> p[i].first>>p[i].second;
    priority_queue<int> pq;
    int ind=0;
    sort(p.begin(),p.end(),cmp);
    for (int t = a; t < b; ++t) {
        while(ind<n&&p[ind].first<=t){
        	if(p[ind].first<b) pq.push(p[ind].second);
        	ind++;
		}
		if(!pq.empty()) {
			val+=pq.top();
			pq.pop();
		}
		else t=p[ind].first-1;
		if(pq.empty()&&ind==n) break;
    }
    cout << val;
    return 0;
}

