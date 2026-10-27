#include <bits/stdc++.h>
using namespace std;
int ans[100003][330];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, q;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for(int k=1;k<=sqrt(n);k++){
    	for(int i=n;i>=0;i--) ans[i][k]=ans[min(100002,i+k+a[i])][k]+1;
	}
    cin >> q;
    while (q--) {
        int p, k, st = 0;
        cin >> p >> k;
        if(k>=sqrt(n)){
        	while (p <= n) {
	            p += a[p] + k;
	            st++;
	        }
	        cout << st << "\n";
	        continue;
		}
		cout << ans[p][k] << "\n";
    }
    return 0;
}

