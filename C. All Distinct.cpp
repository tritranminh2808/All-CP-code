#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		set < int> st;
		 for(int i=0;i<n;i++){
			int k; cin >> k;
			st.insert(k);
		}
		if(st.size()%2!=n%2) {
			cout << st.size()-1 << '\n';
		}
		else cout << st.size() << "\n";
	}
	return 0;
}
