#include <bits/stdc++.h>
using namespace std;
int xuli(vector<vector<char>> ma) {
    if (ma.empty()) return 0;
    int m = ma.size();
    int n = ma[0].size();
    vector<int> h(n + 1, 0);
    int sss = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ma[i][j] == 'W)  {
                [j] += 1;
            } else {
                h[j] = 0;
            }
        }
        stack<int> s;
        s.push(-1);
        for (int j = 0; j <= n; ++j) {
            while (s.top() != -1 && h[j] < h[s.top()] {
                int he = h[s.top()];
                s.pop();
                int w = j - s.top() - 1;
                sss = max(sss, he * w);
            }
            s.push(j);
        }
    }
    return sss;
}
int main() {
//	freopen("maxrect.inp","r",stdin);
//	freopen("maxrect.out","w",stdout);
    int m, n;
    cin >> m >> n;
    vector<vector<char>> a(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    cout << xuli(a);
    return 0;
}
