#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,greater<int>,rb_tree_tag,
tree_order_statistics_node_update> sech_set;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//	freopen("kite.inp","r",stdin);
//	freopen("kite.out","w",stdout);
	int n ; cin >> n;
	sech_set st;
	st.insert(1);
	st.insert(1);
	cout << st.size();return 0;
	for(int i=0;i<n;i++){
		int a;cin>> a;
		st.insert(a);
		auto k=st.order_of_key(a);
		cout << k+1 << "\n";
	}
	return 0;
}
