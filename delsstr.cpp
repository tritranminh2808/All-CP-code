#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7, base=257;
int power[1000005],hs[1000005];
bool check(vector <char> v, string s){
	for(int i=0;i<s.length();i++) if(s[i]!=v[v.size()-s.length()+i]) return false;
	return true;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	power[0]=1;
	for(int i=1;i<=1000000;++i) power[i]=power[i-1]*base%mod;
	string s,t; cin >> s >> t;
	int hst=0;
	s='!'+s;
//	t='!'+t;
	int n=s.length();
	for(int i=0;i<t.length();i++) hst=(hst*base+t[i]+1)%mod;
	vector <char> st;
	st.push_back('!');
	for(int i=0;i<t.length();i++) st.push_back(s[i+1]);
	for(int i=1;i<=t.length();i++) hs[i]=(hs[i-1]*base+st[i]+1)%mod;
	int len=t.length();
	int k=(hs[len]-hs[len-t.length()]*power[t.length()])%mod;
    if(k<0) k += mod;
    if(k==hst){
        for(int j=0;j<t.length();j++){
            st.pop_back();
            len--;
        }
    }
	for(int i=t.length()+1;i<n;i++){
		st.push_back(s[i]);
		len++;
		hs[len]=(hs[len-1]*base+st.back()+1)%mod;
		int k=(hs[len]-hs[len-t.length()]*power[t.length()])%mod;
		if(k<0) k+=mod;
		if(k==hst){
			for(int j=0;j<t.length();j++){
				st.pop_back();
				len--;
			}
		}
	}
	if(st.size()<=1){
		cout << "EMPTY";
		return 0;
	}
	for(int i=1;i<st.size();i++) cout << st[i];
	return 0;
}
