#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[1000005];
int pre[1000005],st[2][1000005];
int node=0;
int cnt[1000005];
void update(int s){
    int id=0;
    for(int i=29;i>=0;i--){
        int x=(s>>i)&1;
        if(!st[x][id]) st[x][id]=++node;
        id=node;
        cnt[id]++;
    }
}
long long cok(int s){
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(st,-1,sizeof(st));
    cin >> n >> k;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        update(a[i]);
    }
    // cout << binbin(10);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]^a[i];
    long long sol=0;
    for(int i=1;i<=n;i++) {
        sol+=cok(pre[i]);
        update(pre[i]);
    }

    return 0;
}