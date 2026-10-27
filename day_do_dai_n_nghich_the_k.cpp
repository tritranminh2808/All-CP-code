#include <bits/stdc++.h>
using namespace std;
const int mod=30011;
int n;
int k; 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    vector <int> prev(k+1),cur(k+1);
    //prev[j]=dp[i-1][j]
    prev[0]=1;
    for(int  i=1;i<=n;i++){
        int sum=0;
        for(int j=0;j<=k;j++){
            sum+=prev[j];
            if (sum>=mod) sum-=mod;
            if (j-i>=0) {
                sum-=prev[j-i];
                if(sum<0) sum+=mod;
            }
            cur[j]=sum;
        }
        swap(prev,cur);
    }
    cout << prev[k];
    return 0;
}