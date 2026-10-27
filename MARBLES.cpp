#include <bits/stdc++.h>
using namespace std;
int solve(string s){
	int dem=0,luu=0,demr=0,demb=0;
	for(auto i:s){
		if(i=='r'){
			if(demr==1){
				dem=max(dem,luu);
				luu=0;
				demr=0;
			}
			else demr=1;
		}
		if(i=='b'){
			if(demb==1){
				dem=max(dem,luu);
				luu=0;
				demb=0;
			}
			else demb=1;
		}
		luu++;
		if(luu==s.length()/2) return luu;
	}
	return dem;
}
int main(){
	freopen("MARBLES.inp","r",stdin);
	freopen("MARBLES.out","w",stdout);
	string a,b;
	cin >> a;
	b+=a;
	b+=a;
	cout << solve(b);
	return 0;
}
