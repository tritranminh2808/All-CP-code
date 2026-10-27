#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("freefood.inp","r",stdin);
	freopen("freefood.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,s; cin >> n >> s;
	vector <pair <int, int> > v(n+1);;
	for(int i=1;i<=n;i++) cin >> v[i].first >> v[i].second;
	sort(v.begin()+1,v.end());
	priority_queue<int> pq;
	int sol=0;
	for(int i=1;i<=n;i++){
		s-=v[i].first-v[i-1].first;
		if(s>=v[i].second){
			sol++;
			pq.push(v[i].second);
			s-=v[i].second;
		}
		else {
			if(!pq.empty()&&v[i].second<pq.top()) {
				s+=pq.top();
				pq.pop();
				pq.push(v[i].second);
				s-=v[i].second;
			}
		}
//		cout << i << ":" << pq.top() << endl;
	}
	cout << pq.size();
}
