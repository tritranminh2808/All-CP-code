#include <bits/stdc++.h>
using namespace std;

pair<int, int> f(int n, vector<pair<int, int>>& s) {
    sort(s.begin(),s.end());
    int maxx=0,l=s[0].first,r=s[0].second;
    pair<int,int> sol={l, r};
    for (int i=1;i<n;++i) {
        if (s[i].first<=r) r=max(r,s[i].second);
        else {
            if (r-l>maxx) {
                maxx=r-l;
                sol={l,r};
            }
            l=s[i].first; 
			r=s[i].second;
        }
    }
    if (r-l> maxx) sol={l,r};
    return sol;
}

int main() {
    int n,k;
    cin >> k >> n;
    vector<pair<int, int>> s(n);
    for (int i = 0; i < n; ++i) {
    	cin >> s[i].first >> s[i].second;
    	if(s[i].first>s[i].second) s[i].second+=k;
	}
    pair<int, int> res = f(n,s);
    cout << res.first << " " << res.second ;
    return 0;
}

