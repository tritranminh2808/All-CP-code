#include <iostream>
#include <cmath>

using namespace std;

long long tinh(long long n, long long m) {
   
    long long min = (n + 1) / 2;

    if (min % m == 0) {
        return min;
    } else {
        return min + (m - min % m);
    }
}

int main() {
    long long n, m;
    cin >> n >> m;

    long long res = tinh(n, m);

    cout << res << endl;

    return 0;
}

