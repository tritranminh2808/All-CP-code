#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("goat.inp","r",stdin);
	freopen("goat.out","w",stdout);
	string s; cin >> s;
	stack <char> st;
	for(auto i :s){
		if(st.empty()){
			st.push(i);
			continue;
		}
		if(i=='>') st.push(i);
		else if(i=='<'){
			if(st.top()=='>')st.pop();
			else st.push(i);
		}
	}
	cout << st.size();
}
