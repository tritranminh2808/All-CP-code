#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("WORDS.INP", "r", stdin);
    freopen("WORDS.OUT", "w", stdout);
    
    string s, word;
    getline(cin, s);  // Ð?c toàn b? xâu t? file

    for (char c : s) {
        if (isalpha(c)) {
            word += c;  // N?u là ký t? ch? cái, thêm vào t? hi?n t?i
        } else {
            if (!word.empty()) {
                cout << word << '\n';  // In t? ra file
                word.clear();  // Xóa t? hi?n t?i d? ti?p t?c gom t? m?i
            }
        }
    }

    if (!word.empty()) {
        cout << word << '\n';  // In t? cu?i cùng n?u có
    }

    return 0;
}

