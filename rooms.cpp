#include <bits/stdc++.h>
using namespace std;
vector <int>  den[200005],di[200005],chia[200005];
int gh=-9999;
map <int, vector <int> >  sol;
int main(){
//	freopen("rooms.inp","r",stdin);
//	freopen("rooms.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	vector < pair <int, int> > v(n);
	for(int i=0;i<n;i++){
		cin >> v[i].first >> v[i].second;
		den[v[i].first].push_back(i);
		di[v[i].second].push_back(i);
		gh=max(gh,v[i].second);
	}
	stack <int> st;
	for(int i=n;i>=1;i--) st.push(i);
	for(int i=0;i<=gh;i++){
		for(auto j : chia[i]){
			st.push(j);
		}
		for(auto j : den[i]){
			sol[st.top()].push_back(j+1);
			chia[v[j].second].push_back(st.top());
			st.pop();
		}
	}
	cout << sol.size() << "\n";
	for(auto i : sol){
		for(auto j : i.second) cout << j << " ";
		cout << "\n"; 
	}
}
