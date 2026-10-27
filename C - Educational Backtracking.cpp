#include <iostream>
#include <vector>
using namespace std;

int solve(int i, int mod, const vector<int>& a, int m, vector<vector<int>>& memo) {
    if (i == a.size()) return mod == 0;
    if (memo[i][mod] != -1) return memo[i][mod];

    int add = solve(i + 1, (mod + a[i]) % m, a, m, memo);
    int sub = solve(i + 1, (mod - a[i] + m) % m, a, m, memo);

    return memo[i][mod] = add + sub;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    
    vector<vector<int>> memo(n, vector<int>(m, -1));
    cout << solve(0, 0, a, m, memo) << endl;
    return 0;
}

