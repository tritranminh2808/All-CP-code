#include <iostream>
#include <fstream>
using namespace std;

long long TICH(long long n) {
    long long tam;
    if (n == 0) 
        tam = 0;
    else 
        tam = 1;
    
    while (n != 0) {
        tam *= (n % 10);
        n /= 10;
    }
    return tam;
}

int main() {
   // freopen("persist.inp","r",stdin);
//	freopen("persist.out","w",stdout);
    long long n, d, max = 0, ghi = 0;

    cin >> n;
    for (long long i = 1; i <= n; i++) {
        d = 0;
        long long j = i;
        while (j > 9) {
            d++;
            j = TICH(j);
        }
        if (d >= max) {
            max = d;
            ghi = i;
        }
    }

    cout << ghi << " " << max;
    return 0;
}

