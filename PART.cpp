#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canCut(const vector<int>& a, int n, long long k, int length) {
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += a[i] / length;
        if (total >= k) return true; 
    }
    return total >= k;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    
    int left = 1, right = *max_element(a.begin(), a.end());
    int result = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canCut(a, n, k, mid)) {
            result = mid; 
            left = mid + 1;  
        } else {
            right = mid - 1;  
        }
    }
    
    cout << result << endl;
    return 0;
}

