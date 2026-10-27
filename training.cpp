#include <bits/stdc++.h>
#define int long long
using namespace std;
int vt[100];
bool check[100];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q; cin >> n >> q;
	string s; cin >> s;
	for(int i=0;i<n;i++){
		vt[s[i]-'A'+1]++;
	}
	int sol=n;
	while(q--){
		char a,t;cin >> a >> t;
		if(t=='L'&&vt[a-'A'+1]!=0){
			int k=vt[a-'A'+1];
			vt[a-'A'+1]=0;
			vt[a-'A']+=k;
			if(a-'A'==0) {
				if(check[a-'A'+1]==0){
					sol--;
					check[a-'A'+1]=1;
				}
			}
			
		}
		else if(t=='R'&&vt[a-'A'+1]!=0){
			int k=vt[a-'A'+1];
			vt[a-'A'+1]=0;
			vt[a-'A'+2]+=k;
			if(a-'A'+2==n+1) {
				if(check[a-'A'+1]==0){
					sol--;
					check[a-'A'+1]=1;
				}
			}
			
		}
	}
	cout << sol;
	return 0;
}
