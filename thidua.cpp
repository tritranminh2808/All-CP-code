#include <bits/stdc++.h>
using namespace std;
int a[1000005],pre[1000005], preM[1000005],preN[1000005];
int sol=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	int n=s.length();
	s='!'+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='N') a[i]=1;
		if(s[i]=='A') a[i]=-1;
	}
	for(int i=1;i<=n;i++){
		preM[i]=preM[i-1];
		if(s[i]=='M') preM[i]++;
		preN[i]=preN[i-1];
		if(s[i]=='N') preN[i]++;
		pre[i]=pre[i-1]+a[i];
	}
	unordered_map<int, vector <int> > mp;
	mp[0].push_back(0);
	for(int i=1;i<=n;i++){
		if(!mp[pre[i]].empty())for(auto j : mp[pre[i]]) if(preN[i]-preN[j]==preM[i]-preM[j]) sol++;
		mp[pre[i]].push_back(i);
	}
	cout << sol;
	return 0;
}
