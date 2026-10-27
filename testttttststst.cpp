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
    
    int n;
    ll k; cin >> n >> k;
    if(n*10>=k){
        vector <int> v;
        int s=0;
        for(int i=1;i<n;i++){
            int a=rand(1,k/n+1);
            s+=a;
            v.push_back(a);
        }
        if(k-s==0) {
            int x=v.back();
            v.pop_back();
            int thay=rand(1,x);
            x-=thay;
            v.push_back(x);
            v.push_back(thay);
        }
        else v.push_back(k-s);
        shuffle(v.begin(),v.end(),rng);
        for(auto i:v) cout << i << " ";
        return 0;
    }
    int cc=n-1;
    map<ll, int > mp;
    vector <int> v;
    ll s=0;
    while(cc>0){
        ll x=rand(1,k-1);
        if(mp.find(x)==mp.end()){
            v.push_back(x);
            mp[x]++;
            cc--;
        }
    }
    sort(v.begin(),v.end());
    for(auto i:v){
        cout << i-s << " ";
        s=i;
    }
    cout << k-s;
    return 0;
}