#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	freopen("HEIGHT.inp","r",stdin);
	freopen("HEIGHT.out","w",stdout);
    int n;
    cin >> n;
    vector<int> a(n), sorted_a(n), result(n);
    
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sorted_a[i] = a[i];
    }

    sort(sorted_a.begin(), sorted_a.end());

    for (int i = 0; i < n; ++i) {
        result[i] = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin();
    }


    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}

