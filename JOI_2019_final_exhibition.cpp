#include <bits/stdc++.h>
using namespace std;
pair <int, int > a[100005];
int b[100005];
int n,m;
bool cmp(pair <int, int > x,pair <int, int > y){
    if(x.second==y.second) return x.first<y.first;
    return x.second <y.second;
}
bool check(int k){
    if(k==0) return true;
    int id=m-k+1;
    for(int i=1;i<=n;i++){
        if(b[id]<a[i].first) continue;
        id++;
        // if(id>m) break;
    }
    return id>m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i].first >> a[i].second;
    for(int i=1;i<=m;i++) cin >> b[i];
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+m+1);
    int l=0,r=m;
    int sol=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            sol=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout << sol;
    return 0;
}