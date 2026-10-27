#include <iostream>
#define MOD 1000000007
using namespace std;

int R, C;

int main() {
    cin >> R >> C;


    long long ways = 1;

    for (int i = 0; i < R; ++i) {
        ways = (ways * 2) % MOD; 
    }

    for (int i = 0; i < C; ++i) {
        ways = (ways * 2) % MOD; 
    }

    cout << ways << endl;
    return 0;
}

