#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 5;
const long long INF = 1e7 + 5;
long long n, a[MAXN];

int main()
{
    freopen("MAXSUM.INP","r",stdin);
    freopen("MAXSUM.OUT","w",stdout);
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long res = -INF, sum = 0;
    for (int i = 0; i < n; i++)
    {
    	sum=max(a[i], sum+a[i]);
    	res=max(sum,res);
    }
    cout << res;
    return 0;
}
