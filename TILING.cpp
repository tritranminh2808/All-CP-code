#include <iostream>
using namespace std;

int main() {
    // Ð?c d? li?u t? d?u vào
    long long m, n, k;
    cin >> m >> n >> k;

    // Tính s? viên g?ch c?n thi?t theo chi?u dài và chi?u r?ng
    long long tiles_length = (m + k - 1) / k;
    long long tiles_width = (n + k - 1) / k;

    // T?ng s? viên g?ch c?n mua
    long long total_tiles = tiles_length * tiles_width;

    // In k?t qu?
    cout << total_tiles << endl;

    return 0;
}

