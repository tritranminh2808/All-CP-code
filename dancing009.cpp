#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a[n];
    int total = 0;

    for (int i = 0; i < n; ++i) {
        cin >> ws; 
        getline(cin, a[i]);
    }

    string first = "Look at the animals, dancing, dancing,";
    string second = "Look at the animals, dancing to the music.";
    for (char c : first)
        if (isalpha(c)) total += 2;
    for (char c : second)
        if (isalpha(c)) total += 2; 

    for (int i = 0; i < n; ++i) {
        int len = 0;
        for (char c : a[i])
            if (isalpha(c)) len++;

        total += len * (n - i) * 4; 
    }

    cout << total << endl;
    return 0;
}

