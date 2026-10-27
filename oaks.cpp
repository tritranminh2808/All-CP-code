#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q; cin >> n;
	unordered_map<int, vector <int> > mpx,mpy;
	map<pair <int , int > , bool> mp;
	while(n--){
		int a,b; cin>> a >> b;
		mpx[a].push_back(b);
		mpy[b].push_back(a);
		mp[{a,b}]=1;
	}
	for(auto &i:mpx) sort(i.second.begin(),i.second.end());
	for(auto &i:mpy) sort(i.second.begin(),i.second.end());
	cin >> q;
	while(q--){
		int cnt=0;
		int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
		if(x1==x2&&y1==y2){
			if(mp[{x1,y1}]) cout << "1\n";
			else cout << "0\n";
			continue;
		}
		if(x1==x2){
			cnt+=upper_bound(mpx[x1].begin(),mpx[x1].end(),y2)-mpx[x1].begin()-(lower_bound(mpx[x1].begin(),mpx[x1].end(),y1) - mpx[x1].begin());
			cout << cnt << "\n";
			continue;
		}
		if(y1==y2){
			cnt+=upper_bound(mpy[y1].begin(),mpy[y1].end(),x2)-mpy[y1].begin()-(lower_bound(mpy[y1].begin(),mpy[y1].end(),x1) - mpy[y1].begin());
			cout << cnt << "\n";
			continue;
		}
		cnt+=upper_bound(mpx[x1].begin(),mpx[x1].end(),y2)-mpx[x1].begin()-(lower_bound(mpx[x1].begin(),mpx[x1].end(),y1) - mpx[x1].begin());
		cnt+=upper_bound(mpx[x2].begin(),mpx[x2].end(),y2)-mpx[x2].begin()-(lower_bound(mpx[x2].begin(),mpx[x2].end(),y1) - mpx[x2].begin());
		cnt+=upper_bound(mpy[y1].begin(),mpy[y1].end(),x2)-mpy[y1].begin()-(lower_bound(mpy[y1].begin(),mpy[y1].end(),x1) - mpy[y1].begin());
		cnt+=upper_bound(mpy[y2].begin(),mpy[y2].end(),x2)-mpy[y2].begin()-(lower_bound(mpy[y2].begin(),mpy[y2].end(),x1) - mpy[y2].begin());
		if(mp[{x1,y1}]) cnt--;
		if(mp[{x1,y2}]) cnt--;
		if(mp[{x2,y1}]) cnt--;
		if(mp[{x2,y2}]) cnt--;
		cout << cnt << "\n";
	}
}
