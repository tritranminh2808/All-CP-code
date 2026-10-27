#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int median = a[n / 2];

    long long total_distance = 0;
    for (int i = 0; i < n; i++) {
        total_distance += abs(a[i] - median);
    }

    cout << total_distance << endl;

    return 0;
}

