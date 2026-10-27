#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--){
        long long n;cin >> n;
        if(n!=6&&n!=28&&n!=496&&n!=8128&&n!=33550336) cout << "NO\n";
        else cout << "YES\n";
    }
	// int n; cin >> n;
	// if(n>=6) cout << 6 << " ";
	// if(n>=28) cout << 28 << " ";
	// if(n>=496) cout << 496 << " ";
	// if(n>=8128) cout << 8128 << " ";
	return 0;
}
