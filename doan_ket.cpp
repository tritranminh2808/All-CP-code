#include <bits/stdc++.h>
using namespace std;
int a[600005];
int n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    long long res=0;
    /*for(int i=1;i<n;i++) a[i+n]=a[i];
    n=n*2-1;
    long long res=0;
    for(int i=1;i<=k-1;i++){
        vector <int> v;
        long long tong=0;
        for(int j=i;j<=n;j+=k) {
            v.push_back(a[j]);
            tong+=a[j];
        }
        sort(v.begin(),v.end());
        int med=v[v.size()/2+1];
        int tbc=tong/v.size();
        long long t1=0,t2=0;
        for(auto j:v) {
            t1+=abs(j-med);
            t2+=abs(j-tbc);
        }
        res+=min(t1,t2);
    }*/
    int g=__gcd(n,k);

    for (int cc=0;cc<g;cc++) {
        vector<int> v;
        for (int i=cc;i<n;i+=g) v.push_back(a[i]);
        sort(v.begin(), v.end());
        int med = v[v.size()/2];
        for (int j:v) res+=abs(j-med);
    }

    cout << res;
    return 0;
}