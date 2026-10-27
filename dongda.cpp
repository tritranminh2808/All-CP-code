#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=3;i<=n;i++){
		int d=a[i]/3;
		a[i-1]+=d;
		a[i-2]+=d*2;
		a[i]-=d*3;
	}
	long long minn=81273872133;
	for(int i=1;i<=n;i++) minn=min((long long)a[i],minn);
	cout << minn;
	return 0;
}
