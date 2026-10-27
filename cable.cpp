#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
int n,k;
int cntkl[1000005],cntkc[1000005];
bool check(int x){
    priority_queue<int, vector <int> , greater<int> > pq;
    for(int i=1;i<=x;i++) pq.push(a[i]);
    for(int i=x+1;i<=n;i++){
        if(pq.top()+a[i]>k) return false;
        int p=pq.top();
        pq.pop();
        pq.push(p+a[i]);
    }
    return true;
}
bool cmp(int a, int b){
    return a>b;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    
    sort(a+1,a+n+1,cmp);
    int l=1,r=n,sol=0;
    while(l<=r){
        int mid=(l+r)/2;
        // cout << mid << "\n";
        if(check(mid)) {r=mid-1;sol=mid;}
        else l=mid+1;
        
    }
    cout << sol;
    return 0;
}