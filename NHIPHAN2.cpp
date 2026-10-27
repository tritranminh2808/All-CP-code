#include <iostream>
#include <vector>
using namespace std;

bool check(string &s) {
    for (int i = 1; i < s.size(); i++)
        if (s[i] == s[i - 1]) return false;
    return true;
}

void solve(int n) {
    vector<string> res;
    for (int i = 0; i < (1 << n); i++) {
        string s;
        for (int j = 0; j < n; j++)
            s += ((i >> j) & 1) ? '1' : '0';
        if (check(s)) res.push_back(s);
    }
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << "\n";
}

int main() {
		freopen("NHIPHAN2.inp","r",stdin);
	freopen("NHIPHAN2.out","w",stdout);
    int n;
    cin >> n;
    solve(n);
    return 0;
}

