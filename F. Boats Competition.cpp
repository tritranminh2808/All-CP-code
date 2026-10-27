#include <bits/stdc++.h>
using namespace std;
int t, n, a[51];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int r = 0;
        for (int s = 2; s <= 2 * n; s++) {
            int c = 0;
            for (int i = 0, j = n - 1; i < j;) {
                if (a[i] + a[j] == s) c++, i++, j--;
                else if (a[i] + a[j] < s) i++;
                else j--;
            }
            r = max(r, c);
        }
        cout << r << '\n';
    }
}

