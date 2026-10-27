#include <bits/stdc++.h>
using namespace std;
int n,l,r,k;
int a[100005];
bool check(int mid){
    int cnt=0,s=0,cur=0;
    for(int i=1;i<=n;i++){
        s+=a[i];
        cur++;
        if(cur>=l&&cur<=r&&s/cur>=mid) {
            cnt++;
            s=0;
            cur=0;
            continue;
        }
    }
    return cnt>=k;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l >> r >> k;
    /*if(k==1){
        int maxx=-1;
        for(int i=1;i<=n;i++) {
            cin >> a[i];
            maxx=max(maxx,a[i]);
        }
        cout << maxx;
        return 0;
    }*/
    int maxx=-1;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        maxx=max(maxx,a[i]);
    }
    int l=0,r=maxx;
    int sol=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) {
            sol=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout << sol;
    return 0;
}