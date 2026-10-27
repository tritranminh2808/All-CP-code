#include <bits/stdc++.h>
#define int long long
using namespace std;
const int c=31,mod=1e9+7;
int hashb[200005],power[200005];
signed main() {
    string s, t;
    cin >> s >> t;
    power[0]=1;
    for(int i=1;i<=200000;i++) power[i]=power[i-1]*c%mod;
    int n=s.size(),m=t.size();
    if (n > m) {
        cout << 0;
        return 0;
    }

    vector<int> fs(26, 0), ft(26, 0);
    for (char c : s) fs[c - 'a']++;
	t='!'+t;
	for(int i=1;i<=m;i++) hashb[i]=(hashb[i-1]*c+t[i]-'a'+1)%mod;
    map <int,bool> mp;
    for (int i = 1; i <=m; ++i) {
        ft[t[i]-'a']++;
        if (i>=n+1) ft[t[i-n]-'a']--;
        if (i>=n&& ft==fs){
        	int k=(hashb[i]-hashb[i-n]*power[n])%mod;
        	if(k<0)k+=mod;
        	mp[k]=1;
		}
        
    }

    cout << mp.size();
    return 0;
}

