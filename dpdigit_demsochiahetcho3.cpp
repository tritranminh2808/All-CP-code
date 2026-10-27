#include <bits/stdc++.h>
using namespace std;
#define int long long
string a;
int f[1000][2][1000];
int backtrack(int id, bool l, int sum){
    if(id==a.size()){
        if(sum%3==0) return 1;
        return 0;
    }
    int &as=f[id][l][sum];
    if(as!=-1) return as;
    as=0;
    for(int i=0;i<10;i++){
        if(l||i<=a[id]-'0') as+=backtrack(id+1,l||i<a[id]-'0',sum+i);
    }
    return as;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a;
    memset(f,-1,sizeof(f));
    cout << backtrack(0,0,0);
}