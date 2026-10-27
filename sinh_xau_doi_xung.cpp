#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
using ll=long long;
ll rand(ll l, ll r){
    return l+rng()%(r-l+1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    vector<int> v;
    for(int i=1;i<=n;i++){
        int x=rand(0,25);
        v.push_back(x);
    }
    // for(int i:v) cout << i << " ";
    // return 0;
    int so_lan_dao=100;
    while(so_lan_dao>0){
        int start=rand(0,n-1);
        while(n-start<2) start=rand(0,n-1);
        int len=rand(1,(n-start)/2);
        int typ=rand(1,2);
        if(typ==1){
            for(int i=0;i<len;i++){
                v[start+len*2-i-1]=v[start+i];
            }
        }
        else {
            for(int i=0;i<len-1;i++){
                v[start+len*2-i-2]=v[start+i];
            }
        }
        so_lan_dao--;
    }
    for(auto i:v) cout << char('a'+i) ;
}