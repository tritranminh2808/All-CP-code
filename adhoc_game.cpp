#include <bits/stdc++.h>
#define int long long
using ldb=long double;
using namespace std;
ldb L;int w,n,m;
const int ee=1e-15;
int a[505],b[505];
ldb cheo(int a, int b){
    return sqrt(a*a+b*b);
}
bool check(int k){
    if(k>n+m||k<2) return false;
    for(int c1=1;c1<=n;c1++){
        int c2=k-c1;
        if(c2>m||c2<1) continue;
        for(int i=1;i<=n-c1+1;i++){
            ldb A=a[i+c1-1]-a[i];
            for(int j=1;j<=m-c2+1;j++) {
                ldb B=b[j+c2-1]-b[j];
                ldb P=cheo(abs(a[i]-b[j]),w)+cheo(abs(a[i+c1-1]-b[j+c2-1]),w)+A+B;
                if(P+ee<=L) return true;
            }
        }
    }
    return false;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>> L >> w >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int j=1;j<=m;j++) cin >> b[j];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    if(n>m) {
        swap(a,b);
        swap(n,m);
    }
    // for(int i=1;i<=n;i++) cout << a[i] << " ";
    int l=0,r=501,sol=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) {
            sol=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout << sol ;
    return 0;
}
