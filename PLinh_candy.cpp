#include<bits/stdc++.h>
using namespace std;
int n;
long long a[1000005],pre[1000005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("candy.inp","r", stdin);
    freopen("candy.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    long long h=1e18;
    for(int i=1;i<=n;i++) h=min(h,abs(pre[n]-pre[i]-pre[i]));
    cout << h;
    return 0;
}