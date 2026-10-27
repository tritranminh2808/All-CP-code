#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
const int p=1e5+5;
int r[p];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("ivector.inp","r",stdin);
	freopen("ivector.out","w",stdout);
	int n; cin >> n;
	vector <int> a(n),b(n),c(n+1);
	for (int i=0;i<n;i++) {
		cin >> a[i];
		c[a[i]]=i;
	}
	indexed_set se;
	for (int i=0;i<n;i++) cin >> b[i];
	r[a[0]]=0;
	se.insert(a[0]);
	for(int i=1;i<n;i++){
		r[a[i]]=se.size() - se.order_of_key(a[i]);
		se.insert(a[i]);
	}
	for(int i=1;i<=n;i++){
		cout << r[i] << " ";
	}
	cout << "\n";
	reverse(b.begin(),b.end());
	vector <int> v;
	v.push_back(n);
	for(int i=1;i<n;i++){
		v.insert(v.begin()+b[i],n-i);
	}
	for( auto i : v) cout << i << " ";
	return 0;
	
}
