#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],pre[100005];
int n;
void cook_chay(){
	int res=0;
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) if(pre[j]-pre[i-1]==j-i+1) res++;
	}
	cout << res;
}

signed main(){
	freopen("daycon.inp","r",stdin);
	freopen("daycon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	if(n<=2000) {
		cook_chay();
		return 0;
	}
	int res=0;
	unordered_map<int, int>  mp;
	mp[0]++;
	for(int i=1;i<=n;i++){
		a[i]--;
		pre[i]=pre[i-1]+a[i];
		if(mp[pre[i]>0]) res+=mp[pre[i]];
		mp[pre[i]]++;
	}
	cout << res;
	return 0;
}
