#include <bits/stdc++.h>
using namespace std;
#define fo freopen
int res=-99;
int main()
{
	fo("COMPRESS004.INP","r",stdin);
	fo("COMPRESS004.OUT","w",stdout);
	string s; cin >> s;
	int n=s.length();
	//vector <char> r;
	for(int i=n;i>=2;i--){
		if(n%i==0){
			
			vector <char> v;
			for(int j=0;j<n/i;j++){
				v.push_back(s[j]);
			}
			bool check=0;
			for(int j=n/i;j<=n-v.size();j+=n/i){
				if(j>=n) break;
				for(int k=0;k<v.size();k++){
					if(v[k]!=s[j+k]){
						check=1;
						break;
					}
				}
				if(check==1) break;
				
			}
			if(check==0) {
				cout << i ;
				for(int i=0;i<v.size();i++) cout << v[i];
				return 0;
			}
		}
	}
	cout << res; 
	//for(int i=0;i<r.size();i++) cout << r[i];
	return 0;
}
