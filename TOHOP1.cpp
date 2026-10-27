#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("tohop1.inp","r",stdin);
    //freopen("tohop1.out","w",stdout);
    int n;
    cin>>n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }

    do {
        for (int num : v) {
            cout << num << " ";
        }
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}

