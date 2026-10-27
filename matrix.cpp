#include <bits/stdc++.h>
using namespace std;
int b[4005][4005];
int main(){
	int k; string s;
	cin >> k;
	cin >> s;
	vector <int> a;
	int n=s.length();
	for(char i : s) a.push_back(int(i)-48);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) b[i][j]=a[i]*a[j];
	}
	int sol = 0;
    for (int x1=0;x1<n;++x1) {
        vector<int>col(n, 0);
        for (int x2 = x1; x2 < n; ++x2) {
            for (int j = 0; j < n; ++j) {
                col[j] += b[x2][j];
            }
            unordered_map<int, int> mp;
            mp[0] = 1;
            int s = 0;

            for (int j = 0; j < n; ++j) {
                s += col[j];
                if (mp.find(s - k) != mp.end()) {
                    sol += mp[s - k];
                }
                mp[s]++;
            }
        }
    }

    cout << sol;
    return 0;
	
}
