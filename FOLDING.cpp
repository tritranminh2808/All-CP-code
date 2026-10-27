#include <iostream>
using namespace std;

char getFoldType(int foldIndex, int n) {
    // Ban d?u, t?t c? các n?p g?p d?u có lo?i là 'A' (lõm)
    char foldType = 'A';

    // Duy?t qua t?ng l?n g?p
    for (int k = 1; k <= n; ++k) {
        // Tính v? trí c?a n?p g?p khi g?p l?n th? k
        int foldPosition = 1 << (k - 1); // Ðây là 2^(k-1)

        // N?u foldIndex n?m trong kho?ng t? foldPosition d?n 2*foldPosition - 1
        if (foldIndex >= foldPosition && foldIndex < 2 * foldPosition) {
            // Ð?i lo?i c?a n?p g?p
            foldType = (foldType == 'A') ? 'B' : 'A';
        }
    }

    return foldType;
}

int main() {
    int n, i, j;
    cin >> n >> i >> j;

    for (int k = i; k <= j; ++k) {
        cout << getFoldType(k, n);
    }

    cout << endl;

    return 0;
}

