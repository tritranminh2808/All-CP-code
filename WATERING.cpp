#include <iostream>
#include <vector>

#include <algorithm>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target("abm,avx2,bmi,bmi2")
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n + 2);
    A[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    A[n + 1] = 0;
    vector<bool> B(n + 2, false);
    for (int i = 1; i <= n; ++i) B[i] = true;
    B[0] = false;
    B[n + 1] = false;
    int k = 0;
    while (true) {
        int s = *max_element(A.begin(), A.end());
        if (s==0) break;
        ++k;
        int x = s;
        int z = s;
        int i = find(A.begin(), A.end(), s) - A.begin();
        int j = i;
        int p = i;
        B[i] = false;
        while (A[i - 1] <= x && B[i - 1] == true) {
            i -= 1;
            x = A[i];
            A[i] = 0;
            B[i] = false;
        }
        while (z >= A[j + 1] && B[j + 1] == true) {
            j += 1;
            z = A[j];
            A[j] = 0;
            B[j] = false;
        }
        A[p] = 0;
    }
    cout<<k;
}

