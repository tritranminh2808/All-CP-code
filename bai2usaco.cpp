#include <bits/stdc++.h>
using namespace std;
int xy[1005][1005],yz[1005][1005],xz[1005][1005];
int main(){
	int n,t; cin >> n >> t;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int sol=0;
	while(t--){
		int x,y,z;cin>> x >> y >> z;
		xy[x][y]++;
		xz[x][z]++;
		yz[y][z]++;
		if(xy[x][y]==n)sol++;
		if(xz[x][z]==n)sol++;
		if(yz[y][z]==n)sol++;
		cout << sol << "\n";
	}
}
