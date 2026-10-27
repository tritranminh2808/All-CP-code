#include <bits/stdc++.h>
using namespace std;
int f[1000005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		memset(f,0,sizeof(f));
		string s; cin >> s;
		f[0]=0;
		int n=s.length();
		for(int i=1;i<n;++i){
			int j=f[i-1];
			while(j>0&&s[i]!=s[j]) j=f[j-1];
			if(s[i]==s[j]) j++;
			f[i]=j;
		}
		for(int i=0;i<n;++i) cout << f[i] << " ";
		cout << "\n";
		int id=0;
		
		while(id<n){
			id+=f[id];
		}
	}
	return 0;
}
