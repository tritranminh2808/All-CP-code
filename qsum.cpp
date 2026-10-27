#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int max_sum = a[l], current_sum = 0;

        for (int i = l; i <= r; ++i) {
            current_sum += a[i];
            max_sum = max(max_sum, current_sum);
            if (current_sum < 0) current_sum = 0;
        }

        cout << max_sum << endl;
    }

    return 0;
}

