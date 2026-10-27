#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        long long start = max(1LL, n - k + 1);
        
        long long odd = 0;
        for (long long i = start; i <= n; i++) {
            if (i % 2 != 0) {
                odd++;
            }
        }
        
        if (odd % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

