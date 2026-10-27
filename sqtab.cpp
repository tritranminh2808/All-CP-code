#include <bits/stdc++.h>
#define int long long
using namespace std;
//int a[1005][1005];
bool cmp(int a, int b){
	return a>b;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("sqtab.inp","r",stdin);
	freopen("sqtab.out","w",stdout);
	int n,k; cin >> n >> k;
	if(n<=1000){
		vector <long long> v;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) v.push_back(i*i+j*j);
		}
		sort(v.begin(),v.end());
		cout<< v[k-1];
		return 0;
	}
	if((n+1)*n/2>=k){
		int cheo=0,ii=1;
		while(cheo<k){
			cheo=(ii+1)*ii/2;
			ii++;
		}
		cheo=ii-1;
		int pos=k-(cheo-1)*cheo/2-1;
//		if(k==(cheo+1)*cheo/2) pos=cheo-1;
		int x=cheo,y=1;
		vector <int> v;
		while(x>0&&y>0){
//			cout << x << " " << y << endl;
			v.push_back(x*x+y*y);
			x--;
			y++;
		}
		sort(v.begin(),v.end());
//		for(auto i: v) cout << i << " ";
		cout << cheo;
	}
	else{
		k=n*n-k+1;
		int cheo=0,ii=1;
		while(cheo<k) {
			cheo=(ii+1)*ii/2;
			ii++;
		}
		cheo=ii-1;
		int pos=k-(cheo-1)*cheo/2-1;
//		if(k==(cheo+1)*cheo/2) pos=cheo-1;
		int x=n-cheo+1,y=n;
		vector <int> v;
		while(x<=n&&y<=n){
			v.push_back(x*x+y*y);
			x++;
			y--;
		}
		sort(v.begin(),v.end(),cmp);
//		for(auto i: v) cout << i << " ";
		cout << v[pos];
	}
	return 0;
}
