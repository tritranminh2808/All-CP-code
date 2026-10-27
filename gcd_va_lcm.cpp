#include <bits/stdc++.h>
using namespace std;
long long gcd(int i, int j){
    if(j==0) return i;
    return gcd(j,i%j);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long x, y;
    cin>> x >> y;
    if(y%x!=0){
        cout << 0;
        return 0;
    }
    long long z=y/x;
    long long cnt=0;
    for(int i=1;i<=sqrt(z);i++){
        if(z%i==0){
            long long j=z/i;
            if(gcd(i,j)==1){
                cnt++;
                if(i!=j) cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}