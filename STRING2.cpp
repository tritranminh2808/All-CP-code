#include <bits/stdc++.h>
using namespace std;
int dp[100023];
void kmp(){
	string s;
	cin >> s;
	dp[0]=0;
	for(int i=1;i<s.length();i++){
		int j = dp[i-1];
		while(j>0&&s[i]!=s[j]){
			j = dp[j-1];
		}
		if(s[i]==s[j])j++;
		dp[i] = j;
	}
	for(int i=0;i<s.length();++i) cout << dp[i] << " ";
}
bool cmp(pair <int, int > a, pair <int, int > b){
	return a.second< b.second;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin >> n >> m;
	int le=n/m;
	string a; cin >> a;
	int ind=1;
	unordered_map< string, vector <int> > mp;
	for(int i=0;i<n;i+=le){
		string ss;
		for(int j=i;j<i+le;j++) ss+=a[j];
		mp[ss].push_back(ind);
		ind++;
	}
	vector <pair <int, int > > ans;
	ind=1;
	while(m--){
		string b; cin >> b;
		ans.push_back({ind,mp[b][mp[b].size()-1]});
		mp[b].pop_back();
		ind++;
	}
	sort(ans.begin(),ans.end(),cmp);
	for(auto i : ans) cout << i.first<< " ";
	return 0;
}
