#include <iostream>
#include <vector>
#include <algorithm>

void printDerangement(std::vector<int>& arr) {
    bool valid = true;
    
    // Ki?m tra xem hoán v? hi?n t?i có ph?i derangement không
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == i + 1) { // Ði?u ki?n a[i] != i
            valid = false;
            break;
        }
    }
    
    // N?u h?p l?, in ra hoán v?
    if (valid) {
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
}

void generateDerangement(std::vector<int>& arr) {
    // Sinh t?t c? các hoán v?
    do {
        printDerangement(arr);
    } while (std::next_permutation(arr.begin(), arr.end()));
}

int main() {
	freopen("tohop2.inp","r",stdin);
	freopen("tohop2.out","w",stdout);
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    
    // Kh?i t?o m?ng t? 1 d?n n
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    
    // Sinh các hoán v? derangement
    generateDerangement(arr);
    
    return 0;
}

