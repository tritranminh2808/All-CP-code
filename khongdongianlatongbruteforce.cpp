#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, q;
    cin >> n ;
    vector<int> a(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            for (int i = l; i <= r; ++i) {
                a[i] += v * (i - l + 1);
            }
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            long long sum = 0;
            for (int i = l; i <= r; ++i) {
                sum += a[i];
            }
            cout << sum << endl;
        }
    }
    
    return 0;
}

