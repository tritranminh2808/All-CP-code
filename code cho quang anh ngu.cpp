#include <bits/stdc++.h>
using namespace std;
int x,y;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	int a[n]; for(int i=0;i<n;i++) cin >> a[i];
	int v; cin >> v;
	bool chck=0,chck1=0;
	for(int i=0;i<n;i++){
		if(chck==0&&a[i]==v){
			x=i;
			chck=1;
		}
		if(chck1==0&&a[n-i-1]>v){
			y=n-i-1;chck1=1;
		}
		if(chck==1&&chck1==1) break;
	}
	cout << x+1 << "\n" << y+1<< "\n";
	for(int i=0;i<n;i++) {
		if(a[i]<v) cout << i+1 << " ";
 	}
	return 0;
}
