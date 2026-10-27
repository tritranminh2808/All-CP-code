#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair <int, int >,null_type,less<pair <int, int > >,rb_tree_tag,
tree_order_statistics_node_update> oset;
const int p=1e5+5;
int r[p];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	oset st;
	int n; cin >> n;
	int id=0;
	while(n--){
		int u; cin >> u;
		st.insert({u,id});
		id++;
	}
	int q; cin >> q;
	
	while(q--){
		id++;
		int c,u;cin >> c >> u;
		if(c==3) st.insert({u,id});
		else {
			if(u>st.size()){
				if(c==1) cout << "-1\n";
				continue;
			}
			auto it=st.find_by_order(u-1);
			if(c==2) st.erase(it);
			else cout << it->first << "\n";
		}
	}
	return 0;
	
}
