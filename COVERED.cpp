#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;


int distance_squared(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int dx = 0, dy = 0;
   
    if (x2 < x3) {
        dx = x3 - x2;
    } else if (x4 < x1) {
        dx = x1 - x4;
    }
    
    if (y2 < y3) {
        dy = y3 - y2;
    } else if (y4 < y1) {
        dy = y1 - y4;
    }
    
    
    return dx * dx + dy * dy;
}

signed main() {
    freopen("COVERED.INP","r",stdin);
    freopen("COVERED.OUT","w",stdout);
    
    int T;
    cin >> T;
    
    while (T--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
       cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        
        int result = distance_squared(x1, y1, x2, y2, x3, y3, x4, y4);
        cout << result << endl;
    }

    
    return 0;
}
