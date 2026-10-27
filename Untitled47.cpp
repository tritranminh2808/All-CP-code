#include <iostream>
#include <tuple>
#include <cmath>
using namespace std;

// Hàm tính gcd s? d?ng thu?t toán Euclid
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Thu?t toán Euclid m? r?ng
tuple<long long, long long, long long> extended_gcd(long long a, long long b) {
    if (b == 0) return make_tuple(a, 1, 0);
    long long d, x1, y1;
    tie(d, x1, y1) = extended_gcd(b, a % b);
    long long x = y1;
    long long y = x1 - (a / b) * y1;
    return make_tuple(d, x, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        long long d, x0, y0;
        tie(d, x0, y0) = extended_gcd(a, b);
        
        if (c % d != 0) {
            cout << "0\n";
        } else {
            x0 *= c / d;
            y0 *= c / d;
            
            long long a_div_d = a / d;
            long long b_div_d = b / d;

            // Ði?u ch?nh x0, y0 d? d?m b?o |x|, |y| <= 10^18
            long long k = 0;
            if (abs(x0) > 1e18 || abs(y0) > 1e18) {
                k = (abs(x0) / abs(b_div_d)) + 1;
                if (x0 > 0) k = -k;
                x0 += k * b_div_d;
                y0 -= k * a_div_d;
            }
            
            // Ð?m b?o nghi?m không quá l?n
            if (abs(x0) > 1e18 || abs(y0) > 1e18) {
                cout << "0\n";
            } else {
                cout << x0 << " " << y0 << "\n";
            }
        }
    }
    return 0;
}

