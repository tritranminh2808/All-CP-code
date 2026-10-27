#include <bits/stdc++.h>
using namespace std;
vector <int> a;
string s;
void tach(){
	for(int i=0;i<s.length();i++){
		int k=0;
		while(s[i]>='0'&&s[i]<='9'){
			k*=10;
			k+=(s[i]-'0');
			i++;
		}
		if(k!=0) a.push_back(k);
	}
}
int sol=1;
vector <int> v[1000005];
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> s;
	tach();
//	for(auto i : a) cout << i << " ";
	int cnt=0,l=0,r=0;
	int n=a.size();
	unordered_map<int, int > mp;
	for(int i=0;i<n;i++){
		for(int j=2;j<=sqrt(a[i]);j++){
			if(a[i]%j==0) v[i].push_back(j);
			while(a[i]%j==0) a[i]/=j;
		}
		if(a[i]!=1) v[i].push_back(a[i]);
	}
//	for(auto i: v[1]) cout << i;
	while(l<=r&&r<n){
		bool check=true;
		for(auto i : v[r]){
			if(mp[i]>=1){
//				cout << ")))))";
				check=false;
				break;
			}
		}
		if(check==true){
			cnt++;
			for(auto i : v[r]) mp[i]++;
			r++;
		}
		else{
			for(auto i : v[l]) mp[i]--;
//			for(auto i : v[r]) mp[i]++;
			cnt--;
			l++;
		}
		sol=max(sol,cnt);
	}
	cout << sol;
	return 0;
}
