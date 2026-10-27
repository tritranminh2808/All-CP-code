#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
using namespace std;
const int p=1e6+5;
long long b[p],a[p];
long long n,m;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    cout <<(long long) max(a[0]*a[1],a[n-1]*a[n-2]);
	
}
 
