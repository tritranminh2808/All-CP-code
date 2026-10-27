#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long min_bottles(long long a, long long b, long long c) {
  
    if (a == c || b == c) return 1;
    if ((a > c && b > c) || (a < c && b < c)) return 0;

    long long g = gcd(abs(a - c), abs(c - b));

    if ((c - b) % g != 0) return 0;

    long long x = abs((c - b) / g);
    long long y = abs((a - c) / g);

    return x + y;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    
    long long result = min_bottles(a, b, c);
    
    cout << result << endl;
    
    return 0;
}

