#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n; // Ð?c s? lu?ng ph?n t?
    unordered_map<int, int> count_map;
    int max_count = 0; // Ð? theo dõi s? l?n xu?t hi?n nhi?u nh?t c?a m?t ph?n t?

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value; // Ð?c t?ng ph?n t?
        count_map[value]++; // Tang s? l?n d?m c?a ph?n t?
        if (count_map[value] > max_count) {
            max_count = count_map[value]; // C?p nh?t s? l?n xu?t hi?n nhi?u nh?t n?u c?n
        }
    }

    // S? lu?ng giá tr? khác nhau là kích thu?c c?a map
    int distinct_values = count_map.size();

    // In ra k?t qu?
    cout << distinct_values << " " << max_count << endl;

    return 0;
}

