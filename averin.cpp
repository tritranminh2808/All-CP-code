#include <bits/stdc++.h>
using namespace std;
int pre[100005];
unordered_map <int, vector<int> > mp;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int sol=n;
	vector <int> a(n+1);
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		mp[a[i]].push_back(i);
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int tbc=pre[j]-pre[i-1];
			if(tbc%(j-i+1)!=0) continue;
			tbc/=(j-i+1);
			//cout << tbc << " " << i << " " << j << "\n";
			for(auto kk : mp[tbc]){
				if(kk>=i&&kk<=j) {
					sol++;
					break;
				}
			}
		}
	}
	cout << sol;
	return 0;
}
