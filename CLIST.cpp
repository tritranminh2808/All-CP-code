#include <iostream>
#include <vector>
#pragma GCC optimize ("03,unroll-loops")
using namespace std;

void p(vector<int>& c, int k, int l) {
    int n = c.size();
    k %= n;  
    l %= n; 

    vector<int> s(c.begin(), c.begin() + k);
    c.erase(c.begin(), c.begin() + k);
    c.insert(c.end(), s.begin(), s.end());

    vector<int> s2(c.end() - l, c.end());
    c.erase(c.end() - l, c.end());
    c.insert(c.begin(), s2.begin(), s2.end());
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, k, l, x;
    cin >> n >> k >> l;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> x;
    x %= n;  

    while (x--) {
        p(v, k, l);
    }

    for (auto i : v) cout << i << " ";
    return 0;
}

