#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
   vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
       cin >> a[i];
    }

    int l = 0;
    int maxn = 0;
    unordered_map<int, int> ff;

    for (int right = 0; right < n; ++right) {
        ff[a[right]]++;
        
        while (ff.size() > 2) {
            ff[a[l]]--;
            if (ff[a[l]] == 0) {
                ff.erase(a[l]);
            }
            ++l;
        }
        
        maxn = max(maxn, right - l + 1);
    }
    
    cout << maxn << "\n";
    
    return 0;
}

