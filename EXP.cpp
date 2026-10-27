#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 1e6;
set<long long> k1;
map<long long, long long> n2, k2; 
long long n, k;

void xu_li2() {
    long long temp_k = k; 
    k2.clear();
    k1.clear();

    for (long long i = 2; i * i <= temp_k; i++) {
        while (temp_k % i == 0) {
            k1.insert(i);
            k2[i]++;
            temp_k /= i;
        }
    }
    if (temp_k != 1) {
        k1.insert(temp_k);
        k2[temp_k]++;
    }
}

void xu_li1() {
    n2.clear();
    for (auto i : k1) {
        long long temp_n = n;
        while (temp_n > 0) {
            n2[i] += temp_n / i;
            temp_n /= i;
        }
    }
}

int main() {
    long long t;
    cin >> t;
    for (long long z = 0; z < t; z++) {
        cin >> n >> k;
        xu_li2();
        xu_li1();
        long long sol = LLONG_MAX; 

        for (auto i : k1) {
            if (k2[i] > 0) {
                sol = min(sol, n2[i] / k2[i]);
            }
        }

        cout << sol << "\n";
    }
    return 0;
}

