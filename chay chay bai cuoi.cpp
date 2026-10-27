#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,a[100005];
int cal(){
    int s=0;
    for(int i=1;i<n;i++)s+=abs(a[i]-a[i-1]);
    return s;
}
int cook(){
    int r=cal();
    for(int l=0;l<n;l++){
        for(int t=l+1;t<n;t++){
            rotate(a+l,a+t,a+t+1);
            r=max(r,cal());
            rotate(a+l,a+l+1,a+t+1);
        }
    }
    return r;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i=0;i<n;i++)cin>>a[i];
    while(q--){
        int t;cin>>t;
        if(t==1){
            int i,x;cin >> i >> x;
            a[i-1]=x;
        }
		else cout<< cook() << "\n";
    }
}

