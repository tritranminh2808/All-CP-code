#include <bits/stdc++.h>
using namespace std;
#define int long long
int st[200005];
int n,k;
int dp[35][1000];
pair <int, int > trace[35][1000];
void cok(){
    cin >> n >> k;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=999;j++) {
            trace[i][j]={-1,-1};
            dp[i][j]=0;
        }
    }
    k=(n-1)*n/2-k;
    int sech=k;
    //int cur=n;
    vector <int> lis;
    dp[0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(dp[i][j]==0) continue;
            for(int x=1;x<=n-i;x++){
                int cost=x*(x-1)/2;
                if(j+cost>k) break;
                 if(!dp[i+x][j+cost]){
                    dp[i+x][j+cost]=1;
                    trace[i+x][j+cost].first=x;
                    trace[i+x][j+cost].second=j;
                }
            }
        }
    }
    if(dp[n][k]==0){
        cout << "0\n";
        return;
    }
    int cur=n;
    //return ;
    while(cur>0){
        int par=trace[cur][sech].first;
        int pre=trace[cur][sech].second;
        lis.push_back(par);
        sech=pre;
        cur-=par;
    }
    reverse(lis.begin(),lis.end()); 
    vector <int> res;
    cur=n;
    for(auto t:lis){
        for(int i=cur-t+1;i<=cur;i++) res.push_back(i);
        cur-=t;
    }
    for(auto i:res) cout << i << " ";
    cout << "\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) cok();
    return 0;
}