#include <bits/stdc++.h>
using namespace std;
#define int long long
int gt[1000005],tg[1000005];
const int mod=1e9+7;
int ckn(int k,int n){
    if(k<0||k>n) return 0;
    if(k>n-k) k=n-k;
    __int128 r=1;
    for(int i=1;i<=k;i++){
        r = r*(n-k+i)/i;
    }
    return (int)r;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // gt[0]=1;
    // for(int i=1;i<=16;i++) gt[i]=gt[i-1]*i;
    int n; cin >> n;
    int x=0;
    vector<int> a;
    while(cin >> x){
        a.push_back(x);
    }
    int k=a.back();
    a.pop_back();
    int res=1;
    // cout << a.size();
    for(int i=1;i<a.size();i++){
        // cout << i << ": ";
        if(a[i]>a[i-1]){
            int k=a[i]-2;
            int n=a.size()-i-1;
            res+=ckn((n-k)/2,n)-ckn((n-k)/2-1,n);
        }
    }
    cout << res << "\n";
    // return 0;
    vector <int> sol;
    sol.push_back(0);
    while(sol.size() < a.size()){
        int rem=a.size()-sol.size()-1;
        int d=sol.back()-1;
        int u=sol.back()+1;
        if(d>=0){
            int cc = 0;
            int t = rem - d;              
            if(t >= 0 && (t % 2 == 0)){
                int x = t / 2;
                cc = ckn(x, rem) - ckn(x-1, rem);
                if(cc < 0) cc = 0;
            }
            if(k > cc){
                k -= cc;
                sol.push_back(u);
            } else sol.push_back(d);
        }
        else  sol.push_back(u);
    
    }

    for(auto i:sol) cout << i << " ";
    return 0;
}