#include <bits/stdc++.h>
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,
tree_order_statistics_node_update> oset;
using namespace std;
ll n,k;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	if(k==n){
		priority_queue<int, vector <int> , greater <int> > pq;
		for(int i=1;i<=n;i++){
			int x; cin >> x;
			pq.push(x);
			cout << pq.top() << "\n";
		}
		return 0;
	}
	else if(k==2){
		ll s1=0,s2=0;
		oset st;
		for(int i=0;i<n;i++){
			int x; cin >> x;
			st.insert(x);
			int k=st.order_of_key(x);
			if(k%2==0) 
			cout << k << " ";
		}
		return 0;
	}
	multiset<ll> st;
	for(int i=0;i<n;i++) {
		ll x; cin >> x;
		st.insert(x);
		ll id=1,sol=0;
		for(auto i:st){
			if(id%k==1) sol+=i;
			id++;
		}
		cout << sol << "\n";
	}
	return 0;
}
