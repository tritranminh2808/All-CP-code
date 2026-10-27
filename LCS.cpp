#include <bits/stdc++.h>
using namespace std;
//int dp[1001][1001];
char x[1001],y[1000005];
int main() {
	freopen("lcs.inp","r",stdin);
	freopen("lcs.out","w",stdout);
	string lcs;
    string a, b;
    cin >> a >> b;
    for(int i=0;i<a.length();i++) x[i+1]=a[i];
    for(int i=0;i<b.length();i++) y[i+1]=b[i];
    int n=a.length(),m=b.length();
    vector < vector <int>> dp(n+1,vector <int> (m+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i] == y[j]) dp[i][j] = dp[i - 1][j - 1] + 1; 
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            //cout << dp[i][j] << " ";
        }
    }
    int i=n,j=m;
    while(i>0&&j>0){
    	if(a[i-1]==b[j-1]){
    		lcs=a[i-1]+lcs;
    		i--;j--;
		}
		else if(dp[i-1][j]>dp[i][j-1]) i--;
		else j--;
	}
    cout << lcs;
    return 0;
}
