#include <bits/stdc++.h>
using namespace std;
struct pl{
    int l,r,id;
};
pl q[200005];
int n,m;
bool cmp(pl x, pl y){
    return x.l < y.l;
}
int a[200005];
int st[2][1000005],res[200005];
void update(int t,int i, int v){
    for(;i<=m;i+=i&-i) st[t][i]+=v;
}
int find(int t,int i){
    int s=0;
    for(;i>0;i-=i&-i) s+=st[t][i];
    return s;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        if(i%2==0) update(1,m-a[i],1);
        else update(0,a[i],1);
    }
    int sol=INT_MAX,cnt=0;
    for(int i=1;i<=m;i++){
        int x=find(0,m)-find(0,i-1)+find(1,i-1);
        // cout << i << " " << x << "\n";
        if(x<sol){
            sol=x;
            cnt=1;
        }
        else if(x==sol) cnt++;
    }
    cout << sol << " " << cnt;
    return 0;
}