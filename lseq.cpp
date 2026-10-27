#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,SZ,sol;
int pre[1000005];
signed main() {
	memset(pre, 0, sizeof(pre));
	freopen("lseq.inp","r",stdin);
	freopen("lseq.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> v;
    int ze = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if (k == 0) ze++;
        else v.push_back(k);
    }
    if(v.empty()){
    	cout << ze;
    	return 0;
	}
    sort(v.begin(), v.end());
    vector<pair<int, int>> a;
    a.push_back({v[0], v[0]});
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == v[i - 1] + 1) {
            a.back().second++;
        } else {
            a.push_back({v[i], v[i]});
        }
    }
	for(int i=0;i<a.size()-1;i++)pre[i+1]=pre[i]+max(a[i+1].first-a[i].second-1,(int)0);
    for (int i = 0; i < a.size(); i++) {
		int ngansach=ze;
		int k=pre[i];
		auto r=upper_bound(pre+i,pre+a.size(),ngansach+k)-pre-1;
		int x=pre[r]-pre[i];
		ngansach-=max((int)0,x);
		sol=max(sol,a[r].second-a[i].first+1+ngansach);
    }

    cout << sol;
    return 0;
}

