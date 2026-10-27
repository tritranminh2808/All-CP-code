#include <bits/stdc++.h>
#define int long long
using namespace std;
long double v[5000005];
signed main(){
	int n, V; cin >> n >> V;
	
	int maxd=-1;
	while(n--){
		int d,h,a,b; cin >> d >> h >> b >> a;
		maxd=max(maxd,d);
		for(int i=0;i<h;i++)	v[d+i]+=b*a;
	}
	long double h=0;
//	for(int i=0;i<10; i ++) cout << v[i] << ' ';
	//cout << maxd;
	for(int i=0;i<=maxd;i++){
	//	cout << i << " " << v[i] << "\n";
		if(v[i]>0){
			h=i;
			if(V-v[i]>0) V-=v[i];
			else{
			//	h+=(long double)V/v[i];
				cout << fixed << setprecision(2) << (long double)h+(long double)V/v[i];
				return 0;
			}
		}
	}
	return 0;
}
