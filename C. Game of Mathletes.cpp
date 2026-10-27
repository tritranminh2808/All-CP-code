#include <bits/stdc++.h>
using namespace std;
int f[400005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		for(int i=0;i<400001;i++) f[i]=0;
		int n,k; cin >> n >> k;
		vector <int> v;
		int score=0;
		for(int i=0;i<n;i++){
			int x; cin >> x;
			if(x>k) continue;
			if(f[k-x]>0){
				score++;
				f[k-x]--;
			}
			else f[x]++;
		}
		cout << score << "\n";
	}
	return 0;
}
