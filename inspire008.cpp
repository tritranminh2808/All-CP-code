#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("inspire008.inp", "r", stdin);
    freopen("INSPIRE008.out", "w", stdout);
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s,a;
        getline(cin,a);
        int n=a.length();
        if(n%2!=0){
        	cout << "NO\n";
        	continue;
		}
		int A=0,B=0;
        for(char i:a) {
        	if(i=='(') A++;
        	if(i==')') B++;
        	
    	}
    	int X=n/2-A,Y=n/2-B;
    	for(int i=0;i<n;i++){
    		if(a[i]=='*'){
    			if(X>0){
    				a[i]='(';
    				X--;
				}
				else{
    				a[i]=')';
    				Y--;
				}
			}
			if(Y==0) break;
		}
		for(char i:a) if(i=='('||i==')') s+=i;
        if(s.length()!=a.length()){
        	cout << "NO\n";
        	continue;
		}
		
      
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
    
    return 0;
}

