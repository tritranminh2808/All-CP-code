#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1000005];

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int rand(int l, int r){
    return l+rng()%(r-l+1);
}
bool check(int t, int k){
    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(a[i]%k==0) cnt++;
        if(cnt*2>=n+(n%2)) return true;
    }
    return cnt*2>=n+(n%2);
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
    int cc=20;
    int res=1;
    while(cc--){
        int r=rand(1,n);
        int x=a[r];
        for(int i=1;i<=sqrt(x);i++){
            if(x%i==0){
                if(check(x,i)) res=max(res,i);
                if(check(x,x/i)) res=max(res,x/i);
            }
        }
    }
    cout << res;
	return 0;
}
