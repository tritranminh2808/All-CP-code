#include <bits/stdc++.h>
using namespace std;
long long t,res;
int main()
{
	freopen("COUNT007.inp","r",stdin);
	freopen("COUNT007.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n; cin >> n; int a[n];
	for(int i=0;i<n;i++) {
		cin >> a[i];
		t+=a[i];
	}
	t/=3;
	int t1=0,t2=0;
	for(int i=0;i<n-2;i++){
		t1+=a[i];
		if(t1==t){
			int j=n-1;
			for(int j=n-1;j>i+1;j--){
				t2+=a[j];
				if(t2==t) res++;
			}
		}
		t2=0;
	}
	cout << res;
	return 0;
}
