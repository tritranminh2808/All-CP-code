#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const long long INF = 1e6 + 5;
long long n, a[MAXN],pre[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (long long i = 1; i <= n; i++) {
    	cin >> a[i];
    	pre[i]=pre[i-1]+a[i];
    }
    
    long long res = -INF;
    for(int i=1;i<=n;i++){
    	for(int j=i+3;j<=n;j+=2){
    		res=max(res,pre[j]-pre[i-1]);
		}
	}
    cout << res;
    return 0;
}

