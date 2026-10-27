#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Hàm tính s? u?c s? chính phuong c?a x
int countPerfectSquareDivisors(int x) {
    int count = 0;
    int sqrtX = sqrt(x);
    for (int i = 1; i <= sqrtX; ++i) {
        if (x % (i * i) == 0) {
            ++count;
        }
    }
    return count;
}

// Hàm ti?n x? lý s? lu?ng các u?c s? chính phuong cho t?t c? các s? t? 1 d?n maxN
vector<int> precomputeF(int maxN) {
    vector<int> F(maxN + 1, 0);
    for (int i = 1; i <= maxN; ++i) {
        F[i] = countPerfectSquareDivisors(i);
    }
    return F;
}

// Hàm tính t?ng các f(x) t? L d?n R s? d?ng b?ng F
int sumF(const vector<int>& F, int L, int R) {
    int total = 0;
    for (int x = L; x <= R; ++x) {
        total += F[x];
    }
    return total;
}

int main() {
    int T;
    cin >> T;
    
    // Gi? s? ph?m vi nh? hon 100000 cho phép tính ti?n x? lý
    const int maxN = 100000;
    vector<int> F = precomputeF(maxN);

    while (T--) {
        int L, R;
        cin >> L >> R;

        // N?u L và R d?u nh? hon ho?c b?ng maxN, dùng b?ng F
        if (R <= maxN) {
            cout << sumF(F, L, R) << endl;
        } else {
            // N?u không, c?n x? lý các giá tr? l?n hon maxN
            int total = 0;
            for (int x = L; x <= R; ++x) {
                total += countPerfectSquareDivisors(x);
            }
            cout << total << endl;
        }
    }
    return 0;
}

