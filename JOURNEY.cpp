#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
    freopen("JOURNEY.INP","r",stdin);
    freopen("JOURNEY.OUT","w",stdout);
    int a,b;cin >> a >> b;
    string s; cin >> s;
    int x=0,y=0,dem=0;
    for(int i=0;i<s.length();++i){
    	if(s[i]=='R') x++;
    	else if(s[i]=='L') x--;
    	else if(s[i]=='U' ) y++;
    	else if(s[i]=='D')y--;
    	if(s[i]=='?') dem++;
	}
	vector <char > v;
	while(dem>0){
		if(y>b) {
			v.push_back('D');
			y--;
			dem--;
		}
		if(x==a&&y==b){
			break;
		}
		if(x>a){
			v.push_back('L');
			x--;
			dem--;
		}
		if(x==a&&y==b){
			break;
		}
		if(x<a) {
			v.push_back('R');
			x++;
			dem--;
		}
		if(x==a&&y==b){
			break;
		}
		if(y<b){
			v.push_back('U');
			y++;
			dem--;
		}
		if(x==a&&y==b){
			break;
		}
	}
	if(dem==0){
		if(x!=a||y!=b) {
			cout << "IMPOSSIBLE";return 0;
		}
	}
	else {
		if(dem%2!=0) {
			cout << "IMPOSSIBLE";return 0;
		}
		else while(dem>0){
			v.push_back('D');
			v.push_back('U');
			dem-=2;
		}
	}
	sort(v.begin(),v.end());
	int j=0;
	for(int i=0;i<s.length();++i){
		if(s[i]=='?') {
			s[i]=v[j];
			j++;
		}
		cout << s[i];
	}
    return 0;
}
