#include <bits/stdc++.h>
using namespace std;
//int dp[1001][1001];
char x[1001],y[1000005];
bool check1[100005],check2[100005];
int main() {
	freopen("scs.inp","r",stdin);
	freopen("scs.out","w",stdout);
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
    		lcs+=a[i-1];
    		i--;j--;
		}
		else if(dp[i-1][j]>dp[i][j-1]) {
			lcs+=a[i-1];
			i--;
		}
		else {
			lcs+=b[j-1];
			j--;
		}
	}
	while(i>0) {
        lcs+=a[i-1];
        i--;
    }
    while (j>0) {
        lcs+=b[j-1];
        j--;
    }

    reverse(lcs.begin(), lcs.end());
	cout << lcs;
    return 0;
}
