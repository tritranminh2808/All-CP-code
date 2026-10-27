#include <bits/stdc++.h>
#define int long long
using namespace std;
int sol=0;
map<pair <int, int > , int> mp; 
int n;
signed cook(int x, int y){
	if(mp[{x,y}]==1) return 0;
	int cheo=max(x,y)+min(x,y)-1;
	if(cheo>n) {
		cheo=2*n-cheo;
		int maxx=n*n-cheo*(cheo-1)/2;
		if(cheo%2==1) return maxx-y+2;
		else return maxx-x+2; 
	}
	
	int maxx=cheo*(cheo+1)/2;
	if(cheo%2==0) return maxx-y+1;
	else return maxx-x+1;
	
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//	freopen("reward.inp","r",stdin);
//	freopen("reward.out","w",stdout);
	int a,b; cin >> n >> a >> b;
	string s;
	cin >> s;
	int pox=a,poy=b;
	sol+=cook(pox,poy);
	for(int i=0;i<s.length();i++){
		mp[{pox,poy}]=1;
		if(s[i]=='S') pox++;
		if(s[i]=='N') pox--;
		if(s[i]=='E') poy++;
		if(s[i]=='W') poy--;
//		cout << pox <<" " << poy << ": " << cook(pox,poy) << endl;
		sol+=cook(pox,poy);
	}
	cout << sol;
	return 0;
}
