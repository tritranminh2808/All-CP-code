#include <bits/stdc++.h>
#define int long long
using namespace std;
void xulihaha(int n, map<int,int>& cnt) {
    for(int i=2;i*i<=n;i++) {
        while(n%i==0) {
            cnt[i]++;
            n/=i;
        }
    }
    if (n!=1) cnt[n]++;
    
}

int dem(int m, int n) {
    map<int, int> cnt;
    xulihaha(m,cnt);
    xulihaha(n,cnt);
    int sol=1;
    for (auto it:cnt) sol*=(it.second + 1);
    return sol;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int m, n;
    cin >> m >> n;
    cout << dem(m,n) << "\n";

    return 0;
}

