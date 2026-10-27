#include <bits/stdc++.h>
using namespace std;
long double a[100000], pre[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;  
    cin >> n;
    
    long double sum = 0;
    for (int i = 1; i <= n; i++) {  
        cin >> a[i];
        sum += a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    long double res = 1e18; 
    for (int i = 2; i < n; i++) { 
        for (int j = i; j < n; j++) {  
            res = min(res, (sum - pre[j] + pre[i - 1]) / (n - (j - i + 1)));
        }
    }

    cout << fixed << setprecision(3) << res;
    return 0;
}

