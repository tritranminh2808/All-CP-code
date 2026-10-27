#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int X, n;
    cin >> X >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0;i<n;i++) {
    	int x;
        cin >> x;
        pq.push(x);
    }
    int sol = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        sol += a + b;
        pq.push(a + b);
    }
    cout << sol;
    return 0;
}

