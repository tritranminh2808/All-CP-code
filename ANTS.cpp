#include <bits/stdc++.h>
using namespace std; 
int  main() {
    long long  n, k;
    cin >> n >> k;
    vector<long long > p(n);

    long long  maxx = 0;
    for (long long  i = 0; i < n; ++i) {
        cin >> p[i];
        long long  time;
        if (p[i] > 0) {
            time = k - p[i];  
        } else {
            time = abs(p[i]);  
        }
        maxx = max(maxx, time);
    }

    cout << maxx ;
    return 0;
}
 
