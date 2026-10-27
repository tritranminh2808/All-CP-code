#include <bits/stdc++.h>
using namespace std;

const int p=1e6+1;
int dp[p];

int main() {
    int t;
    cin >> t;
    dp[1]=1;
    for (int i = 2; i < 100001; ++i) {
    	dp[i]=(long long)(pow(2,i-1)-1)%1000000007;
        for(int j=2;j<=sqrt(i);j++){
        	if(i%j==0){
        		dp[i]-=dp[j]%1000000007;
        		if(j!=sqrt(i)) dp[i]-=dp[i/j];
			}
		}
    }
    for(int i=0;i<t;i++) {
        int s;
        cin >> s;
        cout << dp[s]%1000000007 << endl;
    }
    return 0;
}

