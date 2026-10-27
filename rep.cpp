#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int n;
vector < pair < int, pair <int , int > > > v;
bool cmp(pair <int , int >  a, pair <int , int >  b){
	if(a.second==b.second) return a.first > b.first;
	return a.second <b.second;
}
int main(){
	freopen("rep.inp","r",stdin);
	freopen("rep.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);
	indexed_set st;
	vector < pair < int , int > > v;
	cin >> n;
	for(int i=0;i<n;i++){
		int l,r; cin >> l >> r;
		v.push_back({l,r});
	}
	sort(v.begin(),v.end(),cmp);
//	for(auto i : v) cout << i.first << " " << i.second << endl;
	for(auto i : v){
		if(st.size()==0){
			st.insert(i.second-1);
			st.insert(i.second);
		}
		else {
			int s=st.order_of_key(i.second+1)-st.order_of_key(i.first);
			if(s<2) st.insert (i.second);
			s=st.order_of_key(i.second+1)-st.order_of_key(i.first);
			if(s<2) {
				st.insert (i.second-1);
			//	cout << i.first << ":" ;for(auto i:st) cout << i << " " ; cout << endl;
			}
		}
	}
	cout << st.size() << endl;
	for(auto i : st) cout << i << " ";
	return 0;
}
