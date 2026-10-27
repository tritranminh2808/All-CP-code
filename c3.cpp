#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt[1000000];
signed main()
{
	int n,x; cin >> n >> x;
	int res=0;
	for(int i=1;i<=n;i++){
        int k; cin >> k;
        if(k+k*k==x) res++;
        res+=cnt[k*k+500*500];
        cnt[x-k+500*500]++;
	}
	cout << res;
	return 0;
}
