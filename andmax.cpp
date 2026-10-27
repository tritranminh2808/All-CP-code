#include <bits/stdc++.h>
#define int long long
using namespace std;
int sol=0;
signed main() {
    int n;
    cin >> n;
    int x=n/3;
    for(int i=x;i>=0;i--){
    	if (((n-3*i)&i)==0) {
            cout << i;
            return 0;
        }
	}
    return 0;
}
