#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("noreps.inp","r",stdin);
	freopen("noreps.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        unordered_map<char, int> mp;
        for (char c : s) mp[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto it = mp.begin(); it != mp.end(); ++it) pq.push({(*it).second, (*it).first});
        string sol;
        pair<int, char> pp = {0, ' '};
        while (!pq.empty()) {
            pair<int, char> t = pq.top(); pq.pop();
            int dem = t.first;
            char ch = t.second;
            sol += ch;
            if (pp.first > 0) pq.push(pp);
            pp = {dem - 1, ch};
        }
        cout << sol << "\n";
    }
    return 0;
}

