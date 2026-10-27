#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("sinhtestbtower.out","w",stdout);
    int n = 500000; 
    cout << n << "\n";

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    for (int i = 0; i < n; i++) {
        int a = rng() % (int)(10 - 1) + 1;
        int b = rng() % (int)(10 - a) + (a + 1);
        int h = rng() % (int)(10) + 1;
        cout << a << " " << b << " " << h << "\n";
    }
    return 0;
}

