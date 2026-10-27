#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using indexed_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
int pre[100005];
int sol=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k; cin >> n >> k;
	vector <int> a(n+1);
	int ind=0;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		if(a[i]==k) ind=i;
		if(a[i]==k) a[i]=0;
		else if(a[i]<k) a[i]=-1;
		else a[i]=1;
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	unordered_map<int,int > mp;
	mp[0]=1;
	int sol=0;
	for(int i=1;i<=n;i++){
	//	cout << pre[i] << " ";
		if(mp[pre[i]]&&i>=ind) {
			sol+=mp[pre[i]];
		//	cout << i << " "<< sol << "\n";
		}
		if(i<ind) mp[pre[i]]++;
		
	}
	//cout <<  sol;
	cout << sol;
}
