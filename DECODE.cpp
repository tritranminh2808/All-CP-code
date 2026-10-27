#include <bits/stdc++.h>
#pragma GCC optimize ("03,unroll-loops")
using namespace std;

int main() {
    //freopen("DECODE.INP", "r", stdin);
    //freopen("DECODE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string s;
    cin >> s;

    string result;  
	
    while(!s.empty())
    {
        int n = s.size();
        if (s.length() % 2 == 1) {
            result += s[0];  
            s.erase(s.begin()); 
        } else {
            result.insert(result.begin(),s[0]);  
            s.erase(s.begin());  
        }
    }

    
    cout << result; 

    return 0;
}

