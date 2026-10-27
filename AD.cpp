#include <bits/stdc++.h>
using namespace std;

int main() {
  //  freopen("AD.INP", "r", stdin);
   // freopen("AD.OUT", "w", stdout);
    
    string a, b;
    cin >> a >> b;

    vector<int> x(26, 0), y(26, 0);

    for (char c : a) x[c - 'a']++;
    for (char c : b) y[c - 'a']++;

    int sol= 0;
    for (int i = 0; i < 26; ++i) {
        sol+= abs(x[i] - y[i]);
    }

    cout << sol<< "\n";

    return 0;
}

