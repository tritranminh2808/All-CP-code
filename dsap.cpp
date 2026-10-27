#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0;i<n;i++) cin >> a[i] >> b[i]; 
    deque<int> dq; 
    int l=0,sol=0; 
    for (int i=0;i<n;i++) {
        while (!dq.empty()&&a[dq.back()]<=a[i]) dq.pop_back();
        dq.push_back(i);
        while (!dq.empty()&&a[dq.front()]>b[i]) {
            l=dq.front()+1;
            dq.pop_front();
            while (!dq.empty()&&dq.front()<l) dq.pop_front();
        }
        sol=max(sol,i-l+1);
    }
    cout << sol;
    return 0;
}

