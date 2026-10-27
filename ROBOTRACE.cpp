#include <bits/stdc++.h>
using namespace std;
int res;
int main(){
	freopen("ROBOTRACE.inp","r",stdin);
	freopen("ROBOTRACE.out","w",stdout);
	int n,d; cin >> n>>d; int a[n]; for(int i=0;i<n;i++) cin >> a[i];
	float r[n];
	for(int i=0;i<n;i++){
		r[i]=(float)d/a[i]+i;
	}
//	for(int i=0;i<n;i++) cout << (float)r[i] << " ";
	for(int i=n-1;i>=1;i--){
		for(int j=0;j<i;j++){
			if((float)r[i]<(float) r[j]) res++;
		}
	}
	cout << res;
	return 0;
}
