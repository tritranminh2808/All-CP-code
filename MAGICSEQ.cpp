#include <bits/stdc++.h>
using namespace std;
int main(){
	// freopen("MAGICSEQ.INP", "r", stdin);
    //freopen("MAGICSEQ.OUT", "w", stdout);
	string s; cin >> s;
	int n=s.length();
	stack <int> st;
	vector <int > sech;
	for(int i=0;i<=n;i++){
		st.push(i+1);
		if(i==n||s[i]=='<'){
			while(!st.empty()) {
				sech.push_back(st.top());
				st.pop();
			}
		}
	}
	for(auto i:sech) cout << i << " ";
	return 0;
}
