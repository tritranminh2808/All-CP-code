#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int L, n;
    cin >> L >> n;
    vector<int> a(n);
     priority_queue<int, vector<int>, greater<int>> pq;
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        L-=a[i];
        pq.push(a[i]);
    }
	if(L!=0) pq.push(L);
	//cout << pq.size();
    int totalCost = 0;

    while (pq.size() > 1) {
        int k=pq.top();
        pq.pop();
        int k2=pq.top();pq.pop();
        totalCost+=k+k2;
        pq.push(k+k2);
    }
    
  cout << totalCost << endl;
    return 0;
}

