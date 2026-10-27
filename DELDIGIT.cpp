#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("DELDIGIT.inp", "r", stdin);
//    freopen("DELDIGIT.out", "w", stdout);
	string s;
	int k;
	cin >> s;
	cin >> k;
	stack<char> st;
	for (int i = 0;i<s.size();++i){
		while (!st.empty() and s[i] > st.top() and k>0){
			st.pop();
			k--;
		}
		st.push(s[i]);
	}
	while (k>0){
		st.pop();
		k--;
	}
	string res;
	while (!st.empty()){
		res+=st.top();
		st.pop();
	}
	reverse(res.begin(), res.end());
	cout << res;
}
