#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int n,k;
int cntkl[1000005],cntkc[1000005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) {
        if(a[i]%2==0) cntkc[i%k]++;
        else cntkl[i%k]++;
    }
    int sol=0;
    for(int i=0;i<=k;i++) sol+=min(cntkl[i],cntkc[i]);
    cout << sol;
    return 0;
}