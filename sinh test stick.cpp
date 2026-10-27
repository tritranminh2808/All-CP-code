#include <bits/stdc++.h>
#define int long long
using namespace std;

void generateTest() {
    srand(time(0));
    int X = rand() % 10000 + 1000;  // T?ng d? dài X t? 100 d?n 1099
    int n = rand() % 100 + 50;  // S? do?n t? 5 d?n 15

    vector<int> a(n);
    for (int i = 0; i < n - 1; i++) {
        a[i] = rand() % (X / n) + 1;  // Ð? dài m?i do?n
    }
    a[n - 1] = X - accumulate(a.begin(), a.end() - 1, 0LL);  // Ð?m b?o t?ng = X

    cout << X << " " << n << "\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}

signed main() {
    generateTest();
    return 0;
}

