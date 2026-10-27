#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("ngoac.inp", "r", stdin);
    freopen("ngoac.out", "w", stdout);
    
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s,a;
        getline(cin,a);
        for(char i:a) if(i=='('||i==')') s+=i;
        if(s.length()!=a.length()){
        	cout << "NO\n";
		}
        else {
        	stack<char> st;
	        bool vv = true;
	
	        for (char c : s) {
	            if (c == '(') {
	                st.push(c);
	            } else {
	                if (!st.empty() && st.top() == '(') {
	                    st.pop();
	                } else {
	                    vv = false;
	                    break;
	                }
	            }
	        }
	 if (!st.empty()) vv = false;

        cout << (vv ? "YES\n" : "NO\n");
		}
    }
    
    return 0;
}

