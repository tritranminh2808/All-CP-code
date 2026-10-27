#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];

int dnc(int l, int r){
    if(l>r) return 0;
    // cout << l << " " << r << "\n";
    int minn=INT_MAX;
    long long res=0;
    for(int i=l;i<=r;i++) minn=min(minn,a[i]);
    for(int i=l;i<=r;i++) a[i]-=minn;
    res+=minn;
    int lf=l;
    for(int i=l;i<=r;i++){
        if(a[i]==0) {
            res+=dnc(lf,i-1);
            lf=i+1;
        }
    } 
    res+=dnc(lf,r);
    return min((long long)r-l+1,res);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    for(int i=1;i<=n;i++) cin >> a[i];
    cout << dnc(1,n);
    return 0;
}