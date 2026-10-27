#include <bits/stdc++.h>

using namespace std;
long long n, a, b;
long long tongUoc(long long m) {
    long long sum = 1;
    for (long long i = 2; i < sqrt(m); ++i) {
        if (m % i == 0) {
            sum += i+m/i;
        }
    }
    long long k=sqrt(m);
    if(k*k==m) sum+=k;
    return sum;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> a >> b;
        if (tongUoc(a) == b && tongUoc(b) == a) {
            cout << "YES";
            cout << "\n";
        } else {
            cout << "NO";
            cout << "\n";
        }
    }
}

